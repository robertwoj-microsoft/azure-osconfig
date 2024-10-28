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

namespace fs = std::filesystem;
struct ReportFailure : std::runtime_error
{
    ReportFailure(const std::string& message) : std::runtime_error(message) {}
};

// struct Context
// {
//     MMI_HANDLE handle;
//     sandbox::Sandbox m_sandbox;
// public:
//     Context() {
//         SecurityBaselineInitialize();
//         handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 4096);
//         if(nullptr == handle) {
//             std::cerr << "SecurityBaselineMmiOpen failed" << std::endl;
//             SecurityBaselineShutdown();
//             exit(-1);
//         }
//     }

//     ~Context() {
//         SecurityBaselineMmiClose(handle);
//         SecurityBaselineShutdown();
//     }

//     MMI_HANDLE handle() const {
//         return handle;
//     }

//     sandbox::Sandbox& sandbox() {
//         return m_sandbox;
//     }

//     int exec(sandbox::Task task) {
//         return m_sandbox.exec(task);
//     }
// };

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

static const std::map < std::string, std::string > rules = {
    { "43119747-263c-2c92-4ce5-726e63259049", "EnsurePermissionsOnEtcSshSshdConfig" },
    { "35868e8c-97eb-4981-ab79-99b25101cc86", "EnsureSshBestPracticeProtocol" },
};

static void test(sandbox::Sandbox& sandbox, std::string payloadKey) {
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

/**
 * @brief Fuzzing entry point
 */
extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* input, std::size_t size) {
    static auto sandbox = sandbox::Sandbox{};

    constexpr auto uuidLen = 36;
    auto task = [input, size]() {
        try
        {
            if (size < uuidLen)
                return -1;

            auto uuid = std::string(reinterpret_cast<const char*>(input), uuidLen);
            auto it = rules.find(uuid);
            if (it == rules.end())
            {
                return -1;
            }

            sandbox.reset();
            if (unpack(input + uuidLen, size - uuidLen) != ARCHIVE_OK)
            {
                sandbox.clear();
                /* In case the archive is invalid, fuzzer won't generate new corpus item if we return -1 */
                return -1;
            }

            /* Isolate child process for graceful cleanup */
            auto pid = fork();
            if (pid == -1)
            {
                std::cerr << "Failed to fork: " << strerror(errno) << std::endl;
                sandbox.clear();
                return -1;
            }

            if (pid == 0)
            {
                std::set<int> descriptors;
                for (const auto& entry : fs::directory_iterator("/proc/self/fd"))
                {
                    descriptors.insert(atoi(entry.path().filename().c_str()));
                }

                /*
                 * Invoke the test
                 */
                test(sandbox, std::move(it->second));

                for (const auto& entry : fs::directory_iterator("/proc/self/fd"))
                {
                    if (std::find(descriptors.begin(), descriptors.end(), atoi(entry.path().filename().c_str())) != descriptors.end())
                    {
                        continue;
                    }

                    char path[PATH_MAX];
                    memset(path, 0, sizeof(path));
                    if (readlink(entry.path().c_str(), path, sizeof(path)) == -1)
                    {
                        std::cerr << "readlink failed: " << strerror(errno) << std::endl;
                        continue;
                    }

                    std::cerr << "Open at exit: " << path << " (" << entry.path() << ")" << std::endl;
                    return EXIT_FAILURE;
                }

                for(const auto& entry : fs::directory_iterator("/tmp"))
                {
                    auto prefix = entry.path().filename().string().substr(0, ::strlen("~osconfig"));
                    std::transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
                    if(prefix == "~osconfig")
                    {
                        std::cerr << "Leftover file found: " << entry.path() << std::endl;
                        return EXIT_FAILURE;
                    }
                }
                return 0;
            }
            else
            {
                // Parent process
                int wstatus = 0;
                if (::waitpid(pid, &wstatus, 0) == -1)
                {
                    std::cerr << "waitpid failed: " << strerror(errno) << std::endl;
                    sandbox.clear();
                    return -1;
                }

                if (!WIFEXITED(wstatus) || 0 != WEXITSTATUS(wstatus))
                {
                    throw ReportFailure("Child process exited abnormally");
                }
            }
        }
        catch (const ReportFailure& e)
        {
            sandbox.clear();
            return EXIT_FAILURE;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed to execute test: " << e.what() << std::endl;
            sandbox.clear();
            return -1;
        }

        sandbox.clear();
        return 0;
    };

    try
    {
        auto result = sandbox.exec(task);
        if (result == EXIT_FAILURE)
        {
            throw ReportFailure("Taks process crashed");
        }

        /* Propagate exit code fron the task callback */
        return result;
    }
    catch (const ReportFailure& e)
    {
        /* Fuzzer reports crash here */
        throw;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to execute task: " << e.what() << std::endl;
        /* Avoid creating new inputs */
        return -1;
    }

    /* Possibly new corpus input will be created now */
    return 0;
}
