#include <cstdint>
#include <string>
#include "Mmi.h"
#include "SecurityBaseline.h"
#include <iostream>
#include "sandbox.hpp"
#include <unistd.h>
#include <archive.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <set>
#include <map>
#include <csignal>
#include <fcntl.h>

extern "C" int LLVMFuzzerRunDriver(int*, char***, int (*)(const uint8_t*, size_t));

namespace fs = std::filesystem;
struct ReportFailure : std::runtime_error
{
    ReportFailure(const std::string& message) : std::runtime_error(message) {}
};

/*
 * Tar file unpacking code is based on libarchive example:
 * https://github.com/libarchive/libarchive/blob/master/examples/untar.c
 */
static int copy_data(archive* reader, archive* writer)
{
    int rc;
    const void* buff;
    size_t size;
    int64_t offset;

    for (;;)
    {
        rc = archive_read_data_block(reader, &buff, &size, &offset);
        if (rc == ARCHIVE_EOF)
            return ARCHIVE_OK;
        if (rc != ARCHIVE_OK)
        {
            // std::cerr << "Failed to read data block: " << archive_error_string(reader) << std::endl;
            return rc;
        }

        rc = archive_write_data_block(writer, buff, size, offset);
        if (rc != ARCHIVE_OK)
        {
            // std::cerr << "Failed to write data block: " << archive_error_string(writer) << std::endl;
            return rc;
        }
    }

    return ARCHIVE_FAILED;
}

static int unpack(const std::uint8_t* data, std::size_t size) noexcept
{
    archive* reader = nullptr, * writer = nullptr;
    int rc = ARCHIVE_FAILED;

    reader = archive_read_new();
    if (reader == nullptr)
    {
        // std::cerr << "Failed to obtain archive reader" << std::endl;
        goto unpack_out;
    }

    writer = archive_write_disk_new();
    if (nullptr == writer)
    {
        // std::cerr << "Failed to obtain archive writer" << std::endl;
        goto unpack_out;
    }

    if ((rc = archive_write_disk_set_options(writer, ARCHIVE_EXTRACT_TIME | ARCHIVE_EXTRACT_PERM | ARCHIVE_EXTRACT_ACL | ARCHIVE_EXTRACT_FFLAGS)) != ARCHIVE_OK)
    {
        // std::cerr << "Failed to set archive write disk options: " << archive_error_string(writer) << std::endl;
        goto unpack_out;
    }

    if ((rc = archive_read_support_format_tar(reader)) != ARCHIVE_OK)
    {
        // std::cerr << "Failed to set archive read support format tar: " << archive_error_string(reader) << std::endl;
        goto unpack_out;
    }

    if ((rc = archive_read_open_memory(reader, data, size)) != ARCHIVE_OK)
    {
        // std::cerr << "Failed to read archive from memory: " << archive_error_string(reader) << std::endl;
        goto unpack_out;
    }

    for (;;)
    {
        archive_entry* entry = nullptr;
        rc = archive_read_next_header(reader, &entry);
        if (rc == ARCHIVE_EOF)
            break;
        if (rc != ARCHIVE_OK)
        {
            // std::cerr << "Failed to read next header: " << archive_error_string(reader) << std::endl;
            goto unpack_out;
        }

        if ((rc = archive_write_header(writer, entry) != ARCHIVE_OK))
        {
            // std::cerr << "Failed to write header: " << archive_error_string(writer) << std::endl;
            goto unpack_out;
        }

        if ((rc = copy_data(reader, writer)) != ARCHIVE_OK)
        {
            // copy_data() prints out message in case of failure
            goto unpack_out;
        }

        if ((rc = archive_write_finish_entry(writer)) != ARCHIVE_OK)
        {
            // std::cerr << "Failed to finish entry: " << archive_error_string(writer) << std::endl;
            goto unpack_out;
        }
    }

    rc = ARCHIVE_OK;
unpack_out:
    archive_read_close(reader);
    archive_read_free(reader);
    archive_write_close(writer);
    archive_write_free(writer);
    return rc;
}

struct rule {
    std::string payloadKey;
    fs::path path;
};

static const std::map < std::string, rule > rules = {
    { "43119747-263c-2c92-4ce5-726e63259049", rule {"auditEnsurePermissionsOnEtcSshSshdConfig", "/etc/ssh/sshd_config"} },
    { "35868e8c-97eb-4981-ab79-99b25101cc86", rule { "EnsureSshBestPracticeProtocol", "/etc/ssh/sshd_config" } },
};

static void test(std::string payloadKey) noexcept {
    SecurityBaselineInitialize();
    auto handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 4096);
    if (nullptr == handle)
    {
        std::cerr << "SecurityBaselineMmiOpen failed" << std::endl;
        SecurityBaselineShutdown();
        return;
    }

    char* payload = nullptr;
    int payloadSizeBytes = 0;

    const auto auditRule = "audit" + payloadKey;
    const auto remediationRule = "remediate" + payloadKey;
    SecurityBaselineMmiGet(handle, "SecurityBaseline", auditRule.c_str(), &payload, &payloadSizeBytes);
    SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiSet(handle, "SecurityBaseline", remediationRule.c_str(), NULL, 0);

    SecurityBaselineMmiClose(handle);
    SecurityBaselineShutdown();
}

static auto g_sandbox = sandbox::Sandbox{};

/**
 * @brief Fuzzing entry point
 */
static const int c_skip_input = -1;
static const int c_valid_input = 0;
static const int c_error = 1;

static int target(const std::uint8_t* input, std::size_t size) noexcept(false)
{
    constexpr std::size_t uuidLen = 36;
    constexpr std::size_t perms_size = 4;
    if (size < uuidLen + perms_size)
        return c_skip_input;

    auto uuid = std::string(reinterpret_cast<const char*>(input), uuidLen);
    auto it = rules.find(uuid);
    if (it == rules.end())
    {
        return c_skip_input;
    }
    input += uuidLen;
    size -= uuidLen;
    auto& rule = it->second;

    try
    {
        g_sandbox.reset();

        /*
         * Change directory to /corpus on the original filesystem, otherwise it will be lost
         */
        auto corpusPath = g_sandbox.getOldRootfs() / "corpus";
        if (::chdir(corpusPath.c_str()) == -1)
        {
            throw std::runtime_error(std::string{ "Failed to change directory to " } + corpusPath.string() + std::string{ ": " } + strerror(errno));
        }

        int perms = std::stoi(std::string{ reinterpret_cast<const char*>(input), perms_size }, nullptr, 8);
        if (perms < 0 | perms > 7777)
        {
            g_sandbox.clear();
            return c_skip_input;
        }
        input += perms_size;
        size -= perms_size;

        /* If perms are 0, skip file creation */
        if (perms > 0)
        {
            auto ec = std::error_code{};
            if (!fs::create_directories(rule.path.parent_path(), ec))
            {
                throw std::runtime_error(std::string{ "Failed to create parent directories: " } + ec.message());
            }

            auto fd = ::open(rule.path.c_str(), O_CREAT | O_EXCL | O_WRONLY, perms);
            if(fd == -1)
            {
                throw std::runtime_error(std::string{ "Failed to create parent directories: " } + strerror(errno));
            }

            while (size)
            {
                auto w = ::write(fd, input, size);
                if(w == -1)
                {
                    if(errno == EINTR)
                        continue;
                    ::close(fd);
                    throw std::runtime_error(std::string{ "Failed to write to file: " } + strerror(errno));
                }

                input += w;
                size -= w;
            }

            ::close(fd);
        }

        // if (unpack(input + uuidLen, size - uuidLen) != ARCHIVE_OK)
        // {
        //     /* In case the archive is invalid, fuzzer won't generate new corpus item if we return -1 */
        //     g_sandbox.clear();
        //     return c_skip_input;
        // }

        std::set<int> descriptors;
        for (const auto& entry : fs::directory_iterator("/proc/self/fd"))
        {
            descriptors.insert(atoi(entry.path().filename().c_str()));
        }

        /*
         * Invoke the test
         */
        test(std::move(rule.payloadKey));

        for (const auto& entry : fs::directory_iterator("/proc/self/fd"))
        {
            if (std::find(descriptors.begin(), descriptors.end(), atoi(entry.path().filename().c_str())) != descriptors.end())
            {
                continue;
            }

            char path[PATH_MAX];
            ::memset(path, 0, sizeof(path));
            if (::readlink(entry.path().c_str(), path, sizeof(path)) == -1)
            {
                std::cerr << "readlink failed: " << strerror(errno) << std::endl;
                continue;
            }

            throw ReportFailure(std::string{ "Open at exit: " } + path + " (" + entry.path().string() + ")");
        }

        for (const auto& entry : fs::directory_iterator("/tmp"))
        {
            auto prefix = entry.path().filename().string().substr(0, ::strlen("~osconfig"));
            std::transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
            if (prefix == "~osconfig")
            {
                throw ReportFailure(std::string{ "Leftover file found: " } + entry.path().string());
            }
        }

        g_sandbox.clear();
    }
    catch (const ReportFailure& e)
    {
        std::cerr << "Reporting failure: " << e.what() << std::endl;
        g_sandbox.clear();
        __builtin_trap();
    }
    catch (const std::invalid_argument& e)
    {
        g_sandbox.clear();
        return c_skip_input;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to execute test: " << e.what() << std::endl;
        g_sandbox.clear();
        __builtin_trap();
    }

    return c_valid_input;
}

static void setup_sigint_handler(void (*handler)(int)) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, nullptr) == -1)
    {
        std::cerr << "Failed to set up SIGINT handler: " << strerror(errno) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv)
{
    auto task = [&]() -> int {
        /*
         * Restore default handler, libfuzzer installs its own handlers
         */
        setup_sigint_handler(SIG_DFL);
        return LLVMFuzzerRunDriver(&argc, &argv, target);
    };

    /* Ignore interrupt here, let libfuzzer decide what to do */
    setup_sigint_handler(SIG_IGN);
    return g_sandbox.exec(task);
}
