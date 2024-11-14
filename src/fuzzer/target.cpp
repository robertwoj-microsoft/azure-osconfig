#include "Mmi.h"
#include "SecurityBaseline.h"
#include "CommonUtils.h"
#include "UserUtils.h"
#include <unistd.h>
#include <fcntl.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <stdexcept>
#include <limits>
#include <vector>

// Tells libfuzzer to skip the input when it doesn't contain a valid target
static const int c_skip_input = -1;

// Tells libfuzzer the input was valid and may be used to create a new corpus input
static const int c_valid_input = 0;

struct size_range
{
    std::size_t min = 1;
    std::size_t max = std::numeric_limits<std::size_t>::max();

    size_range() = default;
    size_range(std::size_t min, std::size_t max) : min(min), max(max) {}
};

// A class to keep a single static initialization of the SecurityBaseline library
struct Context
{
    MMI_HANDLE handle;
    std::string tempdir;
public:
    Context() noexcept(false)
    {
        fprintf(stderr, "Context::Context:%d\n", __LINE__);
        char path[] = "/tmp/osconfig-fuzzer-XXXXXX";
        if(::mkdtemp(path) == nullptr)
        {
            fprintf(stderr, "Context::Context:%d\n", __LINE__);
            throw std::runtime_error(std::string{ "failed to create temporary directory: " } + std::strerror(errno));
        }
        tempdir = path;

        fprintf(stderr, "Context::Context:%d\n", __LINE__);
        SecurityBaselineInitialize();
        fprintf(stderr, "Context::Context:%d\n", __LINE__);
        handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 4096);
        fprintf(stderr, "Context::Context:%d\n", __LINE__);
        if (handle == nullptr)
        {
            fprintf(stderr, "Context::Context:%d\n", __LINE__);
            SecurityBaselineShutdown();
            throw std::runtime_error("failed to initialized SecurityBaseline library");
        }
        fprintf(stderr, "Context::Context:%d\n", __LINE__);
    }

    ~Context() noexcept
    {
        ::remove(tempdir.c_str());
        SecurityBaselineMmiClose(handle);
        SecurityBaselineShutdown();
    }

    std::string nextTempfileName() const noexcept
    {
        static int counter = 0;
        return tempdir + "/" + std::to_string(counter++);
    }

    std::string makeTempfile(const char* data, std::size_t size) const noexcept(false)
    {
        auto path = nextTempfileName();
        auto fd = ::open(path.c_str(), O_EXCL | O_CREAT | O_WRONLY | O_TRUNC, 0600);
        while (size)
        {
            auto written = ::write(fd, data, size);
            if (written == -1)
            {
                ::close(fd);
                throw std::runtime_error(std::string{ "failed to write to temporary file: " } + std::strerror(errno));
            }

            size -= written;
            data += written;
        }
        ::close(fd);

        return path;
    }

    std::string extractVariant(const char*& data, std::size_t& size, size_range range = size_range{}) const noexcept
    {
        auto variant = std::string(data, size);
        auto pos = variant.find('.');
        if (pos == std::string::npos || pos < range.min || pos > range.max)
        {
            return {};
        }

        data += pos + 1;
        size -= pos + 1;
        return variant.substr(0, pos);
    }

    void remove(const std::string& path) const noexcept
    {
        ::remove(path.c_str());
    }
};

static int LoadStringFromFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto filename = context.makeTempfile(data, size);
    free(LoadStringFromFile(filename.c_str(), true, nullptr));
    context.remove(filename);
    return 0;
}

static int GetNumberOfLinesInFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto filename = context.makeTempfile(data, size);
    GetNumberOfLinesInFile(filename.c_str());
    context.remove(filename);
    return 0;
}

static int SavePayloadToFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto filename = context.nextTempfileName();
    SavePayloadToFile(filename.c_str(), data, size, nullptr);
    context.remove(filename);
    return 0;
}

static int AppendPayloadToFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto filename = context.makeTempfile(nullptr, 0);
    AppendPayloadToFile(filename.c_str(), data, size, nullptr);
    context.remove(filename);
    return 0;
}

static int SecureSaveToFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto filename = context.nextTempfileName();
    SecureSaveToFile(filename.c_str(), data, size, nullptr);
    context.remove(filename);
    return 0;
}

static int AppendToFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto filename = context.makeTempfile(nullptr, 0);
    AppendToFile(filename.c_str(), data, size, nullptr);
    context.remove(filename);
    return 0;
}

static int ReplaceMarkedLinesInFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto marker = context.extractVariant(data, size);
    if (marker.empty())
    {
        return c_skip_input;
    }

    auto newline = context.extractVariant(data, size);
    if (newline.empty())
    {
        return c_skip_input;
    }

    auto comment = context.extractVariant(data, size, size_range{ 1, 1 });
    if (comment.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    ReplaceMarkedLinesInFile(filename.c_str(), marker.c_str(), newline.c_str(), comment.at(0), true, nullptr);
    context.remove(filename);
    return 0;
}

static int CheckFileSystemMountingOption_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto mountDirectory = context.extractVariant(data, size);
    if (mountDirectory.empty())
    {
        return c_skip_input;
    }

    auto mountType = context.extractVariant(data, size);
    if (mountType.empty())
    {
        return c_skip_input;
    }

    auto desiredOption = context.extractVariant(data, size);
    if (desiredOption.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckFileSystemMountingOption(filename.c_str(), mountDirectory.c_str(), mountType.c_str(), desiredOption.c_str(), &reason, nullptr);
    context.remove(filename);
    free(reason);
    return 0;
}

static int CharacterFoundInFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto what = context.extractVariant(data, size, size_range{ 1, 1 });
    if (what.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    CharacterFoundInFile(filename.c_str(), what.at(0));
    context.remove(filename);
    return 0;
}

static int CheckNoLegacyPlusEntriesInFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckNoLegacyPlusEntriesInFile(filename.c_str(), &reason, nullptr);
    context.remove(filename);
    free(reason);
    return 0;
}

static int FindTextInFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto text = context.extractVariant(data, size);
    if (text.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    FindTextInFile(filename.c_str(), text.c_str(), nullptr);
    context.remove(filename);
    return 0;
}

static int CheckTextIsFoundInFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto text = context.extractVariant(data, size);
    if (text.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckTextIsFoundInFile(filename.c_str(), text.c_str(), &reason, nullptr);
    context.remove(filename);
    free(reason);
    return 0;
}

// Skipping CheckTextIsNotFoundInFile due to similarity

// Skipping CheckMarkedTextNotFoundInFile due to potential of arbitrary command execution
// static int CheckMarkedTextNotFoundInFile_target(Context& context, const char* data, std::size_t size) noexcept
// {
//     auto text = context.extractVariant(data, size);
//     if (text.empty())
//     {
//         return c_skip_input;
//     }

//     auto marker = context.extractVariant(data, size);
//     if (marker.empty())
//     {
//         return c_skip_input;
//     }

//     auto comment = context.extractVariant(data, size, size_range{ 1, 1 });
//     if (comment.empty())
//     {
//         return c_skip_input;
//     }

//     auto filename = context.makeTempfile(data, size);
//     char* reason = nullptr;
//     CheckMarkedTextNotFoundInFile(filename.c_str(), text.c_str(), marker.c_str(), comment.at(0), &reason, nullptr);
//     context.remove(filename);
//     free(reason);
//     return 0;
// }

// Skipping CheckTextNotFoundInEnvironmentVariable due to potential of arbitrary command execution
// static int CheckTextNotFoundInEnvironmentVariable_target(Context& context, const char* data, std::size_t size) noexcept
// {
//     auto variable = context.extractVariant(data, size);
//     if (variable.empty())
//     {
//         return c_skip_input;
//     }

//     auto text = context.extractVariant(data, size);
//     if (text.empty())
//     {
//         return c_skip_input;
//     }

//     auto strict = context.extractVariant(data, size, size_range{ 1, 1 });
//     if (strict.empty())
//     {
//         return c_skip_input;
//     }

//     char* reason = nullptr;
//     CheckTextNotFoundInEnvironmentVariable(variable.c_str(), text.c_str(), strict.at(0) == '1' ? true : false, &reason, nullptr);
//     free(reason);
//     return 0;
// }

static int CheckFileContents_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto text = context.extractVariant(data, size);
    if (text.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckFileContents(filename.c_str(), text.c_str(), &reason, nullptr);
    context.remove(filename);
    free(reason);
    return 0;
}

static int CheckLineNotFoundOrCommentedOut_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto text = context.extractVariant(data, size);
    if (text.empty())
    {
        return c_skip_input;
    }

    auto comment = context.extractVariant(data, size, size_range{ 1, 1 });
    if (comment.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckLineNotFoundOrCommentedOut(filename.c_str(), comment.at(0), text.c_str(), &reason, nullptr);
    context.remove(filename);
    free(reason);
    return 0;
}

// Skipping CheckTextFoundInCommandOutput due to arbitrary command execution
// static int CheckTextFoundInCommandOutput_target(Context& context, const char* data, std::size_t size) noexcept
// {
//     auto command = context.extractVariant(data, size);
//     if (command.empty())
//     {
//         return c_skip_input;
//     }

//     auto text = std::string(data, size);
//     char* reason = nullptr;
//     CheckTextFoundInCommandOutput(command.c_str(), text.c_str(), &reason, nullptr);
//     free(reason);
//     return 0;
// }

// Skipping CheckTextNotFoundInCommandOutput due to similarity to CheckTextFoundInCommandOutput

static int GetStringOptionFromBuffer_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto option = context.extractVariant(data, size);
    if (option.empty())
    {
        return c_skip_input;
    }

    auto separator = context.extractVariant(data, size, size_range{ 1, 1 });
    if (separator.empty())
    {
        return c_skip_input;
    }

    auto buffer = std::string(data, size);
    GetStringOptionFromBuffer(buffer.c_str(), option.c_str(), separator.at(0), nullptr);
    return 0;
}

static int GetIntegerOptionFromBuffer_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto option = context.extractVariant(data, size);
    if (option.empty())
    {
        return c_skip_input;
    }

    auto separator = context.extractVariant(data, size, size_range{ 1, 1 });
    if (separator.empty())
    {
        return c_skip_input;
    }

    auto buffer = std::string(data, size);
    GetIntegerOptionFromBuffer(buffer.c_str(), option.c_str(), separator.at(0), nullptr);
    return 0;
}

static int CheckLockoutForFailedPasswordAttempts_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto pamSo = context.extractVariant(data, size);
    if (pamSo.empty())
    {
        return c_skip_input;
    }

    auto comment = context.extractVariant(data, size, size_range{ 1, 1 });
    if (comment.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckLockoutForFailedPasswordAttempts(filename.c_str(), pamSo.c_str(), comment.at(0), &reason, nullptr);
    context.remove(filename);
    free(reason);
    return 0;
}

static int CheckPasswordCreationRequirements_target(Context& context, const char* data, std::size_t size) noexcept
{
    try
    {
        auto integer = context.extractVariant(data, size);
        if (integer.empty())
        {
            return c_skip_input;
        }
        auto retry = std::stoi(integer);

        integer = context.extractVariant(data, size);
        if (integer.empty())
        {
            return c_skip_input;
        }
        auto minlen = std::stoi(integer);

        integer = context.extractVariant(data, size);
        if (integer.empty())
        {
            return c_skip_input;
        }
        auto minclass = std::stoi(integer);

        integer = context.extractVariant(data, size);
        if (integer.empty())
        {
            return c_skip_input;
        }
        auto dcredit = std::stoi(integer);

        integer = context.extractVariant(data, size);
        if (integer.empty())
        {
            return c_skip_input;
        }
        auto ucredit = std::stoi(integer);

        integer = context.extractVariant(data, size);
        if (integer.empty())
        {
            return c_skip_input;
        }
        auto ocredit = std::stoi(integer);

        auto lcredit = std::stoi(std::string(data, size));
        char* reason = nullptr;
        CheckPasswordCreationRequirements(retry, minlen, minclass, dcredit, ucredit, ocredit, lcredit, &reason, nullptr);
        free(reason);
        return 0;
    }
    catch(const std::exception& e)
    {
        return c_skip_input;
    }
}

static int GetStringOptionFromFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto option = context.extractVariant(data, size);
    if (option.empty())
    {
        return c_skip_input;
    }

    auto separator = context.extractVariant(data, size, size_range{ 1, 1 });
    if (separator.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    free(GetStringOptionFromFile(filename.c_str(), option.c_str(), separator.at(0), nullptr));
    return 0;
}

static int GetIntegerOptionFromFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto option = context.extractVariant(data, size);
    if (option.empty())
    {
        return c_skip_input;
    }

    auto separator = context.extractVariant(data, size, size_range{ 1, 1 });
    if (separator.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    GetIntegerOptionFromFile(filename.c_str(), option.c_str(), separator.at(0), nullptr);
    return 0;
}

static int CheckIntegerOptionFromFileEqualWithAny_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto option = context.extractVariant(data, size);
    if (option.empty())
    {
        return c_skip_input;
    }

    auto separator = context.extractVariant(data, size, size_range{ 1, 1 });
    if (separator.empty())
    {
        return c_skip_input;
    }

    static const std::size_t max_values = 1000;
    int* values = new int[max_values];
    std::size_t count = 0;
    while (count < max_values)
    {
        auto value = context.extractVariant(data, size);
        if (value.empty())
        {
            break;
        }

        try
        {
            values[count++] = std::stoi(value);
        }
        catch(const std::exception& e)
        {
            break;
        }
    }

    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckIntegerOptionFromFileEqualWithAny(filename.c_str(), option.c_str(), separator.at(0), values, count, &reason, nullptr);
    context.remove(filename);
    free(reason);
    delete[] values;
    return 0;
}

static int CheckIntegerOptionFromFileLessOrEqualWith_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto option = context.extractVariant(data, size);
    if (option.empty())
    {
        return c_skip_input;
    }

    auto separator = context.extractVariant(data, size, size_range{ 1, 1 });
    if (separator.empty())
    {
        return c_skip_input;
    }

    auto integer = context.extractVariant(data, size);
    if (integer.empty())
    {
        return c_skip_input;
    }

    int value;
    try
    {
        value = std::stoi(integer);
    }
    catch(const std::exception& e)
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    char* reason = nullptr;
    CheckIntegerOptionFromFileLessOrEqualWith(filename.c_str(), option.c_str(), separator.at(0), value, &reason, nullptr);
    context.remove(filename);
    free(reason);
    return 0;
}

static int DuplicateString_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto source = std::string(data, size);
    free(DuplicateString(source.c_str()));
    return 0;
}

static int ConcatenateStrings_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto a = context.extractVariant(data, size);
    if (a.empty())
    {
        return c_skip_input;
    }

    auto b = std::string(data, size);
    free(ConcatenateStrings(a.c_str(), b.c_str()));
    return 0;
}

static int DuplicateStringToLowercase_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto source = std::string(data, size);
    free(DuplicateStringToLowercase(source.c_str()));
    return 0;
}

static int ConvertStringToIntegers_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto separator = context.extractVariant(data, size, size_range{ 1, 1 });
    if (separator.empty())
    {
        return c_skip_input;
    }

    auto source = std::string(data, size);
    int* values = nullptr;
    int count = 0;
    ConvertStringToIntegers(source.c_str(), separator.at(0), &values, &count, nullptr);
    free(values);
    return 0;
}

static int RemoveCharacterFromString_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto what = context.extractVariant(data, size, size_range{ 1, 1 });
    if (what.empty())
    {
        return c_skip_input;
    }

    auto source = std::string(data, size);
    free(RemoveCharacterFromString(source.c_str(), what.at(0), nullptr));
    return 0;
}

static int ReplaceEscapeSequencesInString_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto escapes = context.extractVariant(data, size);
    if (escapes.empty())
    {
        return c_skip_input;
    }

    auto replacement = context.extractVariant(data, size, size_range{ 1, 1 });
    if (replacement.empty())
    {
        return c_skip_input;
    }

    auto source = std::string(data, size);
    free(ReplaceEscapeSequencesInString(source.c_str(), escapes.c_str(), escapes.size(), replacement.at(0), nullptr));
    return 0;
}

static int HashString_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto source = std::string(data, size);
    HashString(source.c_str());
    return 0;
}

static int ParseHttpProxyData_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto source = std::string(data, size);
    char* hostAddress = nullptr;
    int port = 0;
    char* username = nullptr;
    char* password = nullptr;
    ParseHttpProxyData(source.c_str(), &hostAddress, &port, &username, &password, nullptr);
    free(hostAddress);
    free(username);
    return 0;
}

static int CheckCpuFlagSupported_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto cpuFlag = std::string(data, size);
    char* reason = nullptr;
    CheckCpuFlagSupported(cpuFlag.c_str(), &reason, nullptr);
    free(reason);
    return 0;
}

static int CheckLoginUmask_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto desired = std::string(data, size);
    char* reason = nullptr;
    CheckLoginUmask(desired.c_str(), &reason, nullptr);
    free(reason);
    return 0;
}

static int IsCurrentOs_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto name = std::string(data, size);
    IsCurrentOs(name.c_str(), nullptr);
    return 0;
}

static int RemovePrefixBlanks_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto name = std::string(data, size);
    RemovePrefixBlanks(&name[0]);
    return 0;
}

static int RemovePrefixUpTo_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto marker = context.extractVariant(data, size, size_range{ 1, 1 });
    if (marker.empty())
    {
        return c_skip_input;
    }

    auto name = std::string(data, size);
    RemovePrefixUpTo(&name[0], marker.at(0));
    return 0;
}

static int RemovePrefixUpToString_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto marker = context.extractVariant(data, size);
    if (marker.empty())
    {
        return c_skip_input;
    }

    auto name = std::string(data, size);
    RemovePrefixUpToString(&name[0], marker.c_str());
    return 0;
}

static int RemoveTrailingBlanks_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto name = std::string(data, size);
    RemoveTrailingBlanks(&name[0]);
    return 0;
}

static int TruncateAtFirst_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto marker = context.extractVariant(data, size, size_range{ 1, 1 });
    if (marker.empty())
    {
        return c_skip_input;
    }

    auto name = std::string(data, size);
    TruncateAtFirst(&name[0], marker.at(0));
    return 0;
}

static int UrlEncode_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto name = std::string(data, size);
    free(UrlEncode(&name[0]));
    return 0;
}

static int UrlDecode_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto name = std::string(data, size);
    free(UrlDecode(&name[0]));
    return 0;
}

// Skipping IsDaemonActive due to potential of arbitrary command execution
// static int IsDaemonActive_target(const char* data, std::size_t size) noexcept
// {
//     auto name = std::string(data, size);
//     IsDaemonActive(name.c_str(), nullptr);
//     return 0;
// }

static int RepairBrokenEolCharactersIfAny_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto name = std::string(data, size);
    free(RepairBrokenEolCharactersIfAny(name.c_str()));
    return 0;
}

static int RemoveEscapeSequencesFromFile_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto escapes = context.extractVariant(data, size);
    if (escapes.empty())
    {
        return c_skip_input;
    }

    auto replacement = context.extractVariant(data, size, size_range{ 1, 1 });
    if (replacement.empty())
    {
        return c_skip_input;
    }

    auto filename = context.makeTempfile(data, size);
    RemoveEscapeSequencesFromFile(filename.c_str(), escapes.c_str(), escapes.size(), replacement.at(0), nullptr);
    context.remove(filename);
    return 0;
}

static int IsCommandLoggingEnabledInJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    IsCommandLoggingEnabledInJsonConfig(json.c_str());
    return 0;
}

static int IsFullLoggingEnabledInJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    IsFullLoggingEnabledInJsonConfig(json.c_str());
    return 0;
}

static int IsIotHubManagementEnabledInJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    IsIotHubManagementEnabledInJsonConfig(json.c_str());
    return 0;
}

static int GetReportingIntervalFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    GetReportingIntervalFromJsonConfig(json.c_str(), nullptr);
    return 0;
}

static int GetModelVersionFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    GetModelVersionFromJsonConfig(json.c_str(), nullptr);
    return 0;
}

static int GetLocalManagementFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    GetLocalManagementFromJsonConfig(json.c_str(), nullptr);
    return 0;
}

static int GetIotHubProtocolFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    GetIotHubProtocolFromJsonConfig(json.c_str(), nullptr);
    return 0;
}

static int LoadReportedFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    REPORTED_PROPERTY* reported = nullptr;
    LoadReportedFromJsonConfig(json.c_str(), &reported, nullptr);
    free(reported);
    return 0;
}

static int GetGitManagementFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    GetGitManagementFromJsonConfig(json.c_str(), nullptr);
    return 0;
}

static int GetGitRepositoryUrlFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    GetGitRepositoryUrlFromJsonConfig(json.c_str(), nullptr);
    return 0;
}

static int GetGitBranchFromJsonConfig_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto json = std::string(data, size);
    GetGitBranchFromJsonConfig(json.c_str(), nullptr);
    return 0;
}

static int CheckOrEnsureUsersDontHaveDotFiles_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto username = std::string(data, size);
    char* reason = nullptr;
    CheckOrEnsureUsersDontHaveDotFiles(username.c_str(), false, &reason, nullptr);
    free(reason);
    return 0;
}

static int CheckUserAccountsNotFound_target(Context& context, const char* data, std::size_t size) noexcept
{
    auto usernames = std::string(data, size);
    char* reason = nullptr;
    CheckUserAccountsNotFound(usernames.c_str(), &reason, nullptr);
    free(reason);
    return 0;
}

static int SecurityBaselineMmiGet_target(Context& context, const char* data, std::size_t size) noexcept
{
    char* payload = nullptr;
    int payloadSizeBytes = 0;

    auto input = std::string(data, size);
    SecurityBaselineMmiGet(context.handle, "SecurityBaseline", input.c_str(), &payload, &payloadSizeBytes);
    SecurityBaselineMmiFree(payload);
    return 0;
}

// static int SecurityBaselineMmiSet_target(Context& context, const char* data, std::size_t size) noexcept
// {
//     const char* prefix = reinterpret_cast<const char*>(std::memchr(data, '.', size));
//     if (prefix == nullptr)
//     {
//         // Separator not found, skip the input
//         return c_skip_input;
//     }

//     // Include the delimiter
//     prefix++;
//     const auto prefix_size = prefix - data;
//     size -= prefix_size;

//     char* payload = reinterpret_cast<char*>(malloc(size));
//     if(!payload)
//     {
//         return c_skip_input;
//     }
//     memcpy(payload, prefix, size);

//     auto input = std::string(data, prefix_size-1);
//     SecurityBaselineMmiSet(context.handle, "SecurityBaseline", input.c_str(), payload, size);
//     SecurityBaselineMmiFree(payload);
//     return 0;
// }

// List of supported fuzzing targets.
// The key is taken from the input data and is used to determine which target to call.
static const std::map<std::string, int (*)(Context&, const char*, std::size_t)> g_targets = {
    // // { "SecurityBaselineMmiGet.", SecurityBaselineMmiGet_target },
    // // { "SecurityBaselineMmiSet.", SecurityBaselineMmiSet_target },
    // { "GetNumberOfLinesInFile.", GetNumberOfLinesInFile_target },
    // { "LoadStringFromFile.", LoadStringFromFile_target },
    // { "SavePayloadToFile.", SavePayloadToFile_target },
    // { "AppendPayloadToFile.", AppendPayloadToFile_target },
    // { "SecureSaveToFile.", SecureSaveToFile_target },
    // { "AppendToFile.", AppendToFile_target },
    // { "ReplaceMarkedLinesInFile.", ReplaceMarkedLinesInFile_target },
    // { "CheckFileSystemMountingOption.", CheckFileSystemMountingOption_target },
    // { "CharacterFoundInFile.", CharacterFoundInFile_target },
    // { "CheckNoLegacyPlusEntriesInFile.", CheckNoLegacyPlusEntriesInFile_target },
    // { "FindTextInFile.", FindTextInFile_target },
    // { "CheckTextIsFoundInFile.", CheckTextIsFoundInFile_target },
    // // { "CheckMarkedTextNotFoundInFile.", CheckMarkedTextNotFoundInFile_target },
    // // { "CheckTextNotFoundInEnvironmentVariable.", CheckTextNotFoundInEnvironmentVariable_target },
    // { "CheckFileContents.", CheckFileContents_target },
    // { "CheckLineNotFoundOrCommentedOut.", CheckLineNotFoundOrCommentedOut_target },
    // // { "CheckTextFoundInCommandOutput.", CheckTextFoundInCommandOutput_target },
    // { "GetStringOptionFromBuffer.", GetStringOptionFromBuffer_target },
    // { "GetIntegerOptionFromBuffer.", GetIntegerOptionFromBuffer_target },
    // { "CheckLockoutForFailedPasswordAttempts.", CheckLockoutForFailedPasswordAttempts_target },
    // { "CheckPasswordCreationRequirements.", CheckPasswordCreationRequirements_target },
    // { "GetStringOptionFromFile.", GetStringOptionFromFile_target },
    // { "GetIntegerOptionFromFile.", GetIntegerOptionFromFile_target },
    // { "CheckIntegerOptionFromFileEqualWithAny.", CheckIntegerOptionFromFileEqualWithAny_target },
    // { "CheckIntegerOptionFromFileLessOrEqualWith.", CheckIntegerOptionFromFileLessOrEqualWith_target },
    // { "DuplicateString.", DuplicateString_target },
    // { "ConcatenateStrings.", ConcatenateStrings_target },
    // { "DuplicateStringToLowercase.", DuplicateStringToLowercase_target },
    // { "ConvertStringToIntegers.", ConvertStringToIntegers_target },
    // { "RemoveCharacterFromString.", RemoveCharacterFromString_target },
    // { "ReplaceEscapeSequencesInString.", ReplaceEscapeSequencesInString_target },
    // { "HashString.", HashString_target },
    // { "ParseHttpProxyData.", ParseHttpProxyData_target },
    // { "CheckCpuFlagSupported.", CheckCpuFlagSupported_target },
    // { "CheckLoginUmask.", CheckLoginUmask_target },
    // { "IsCurrentOs.", IsCurrentOs_target },
    // { "RemovePrefixBlanks.", RemovePrefixBlanks_target },
    // { "RemovePrefixUpTo.", RemovePrefixUpTo_target },
    // { "RemovePrefixUpToString.", RemovePrefixUpToString_target },
    // { "RemoveTrailingBlanks.", RemoveTrailingBlanks_target },
    // { "TruncateAtFirst.", TruncateAtFirst_target },
    // { "UrlEncode.", UrlEncode_target },
    // { "UrlDecode.", UrlDecode_target },
    // // { "IsDaemonActive.", IsDaemonActive_target },
    // { "RepairBrokenEolCharactersIfAny.", RepairBrokenEolCharactersIfAny_target },
    // { "RemoveEscapeSequencesFromFile.", RemoveEscapeSequencesFromFile_target },
    // { "IsCommandLoggingEnabledInJsonConfig.", IsCommandLoggingEnabledInJsonConfig_target },
    // { "IsFullLoggingEnabledInJsonConfig.", IsFullLoggingEnabledInJsonConfig_target },
    // { "IsIotHubManagementEnabledInJsonConfig.", IsIotHubManagementEnabledInJsonConfig_target },
    // { "GetReportingIntervalFromJsonConfig.", GetReportingIntervalFromJsonConfig_target },
    // { "GetModelVersionFromJsonConfig.", GetModelVersionFromJsonConfig_target },
    // { "GetLocalManagementFromJsonConfig.", GetLocalManagementFromJsonConfig_target },
    // { "GetIotHubProtocolFromJsonConfig.", GetIotHubProtocolFromJsonConfig_target },
    // { "LoadReportedFromJsonConfig.", LoadReportedFromJsonConfig_target },
    // { "GetGitManagementFromJsonConfig.", GetGitManagementFromJsonConfig_target },
    // { "GetGitRepositoryUrlFromJsonConfig.", GetGitRepositoryUrlFromJsonConfig_target },
    // { "GetGitBranchFromJsonConfig.", GetGitBranchFromJsonConfig_target },
    // { "CheckOrEnsureUsersDontHaveDotFiles.", CheckOrEnsureUsersDontHaveDotFiles_target },
    { "CheckUserAccountsNotFound.", CheckUserAccountsNotFound_target },
};

// libfuzzer entry point
extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
    return 0;
    // static Context context;

    // const auto* input = reinterpret_cast<const char*>(data);
    // const auto* prefix = reinterpret_cast<const char*>(std::memchr(input, '.', size));
    // if (prefix == nullptr)
    // {
    //     // Separator not found, skip the input
    //     return c_skip_input;
    // }

    // // Include the separator
    // prefix++;
    // const auto prefix_size = prefix - input;
    // auto it = g_targets.find(std::string(input, prefix_size));
    // if(it == g_targets.end())
    // {
    //     // Target mismatch, skip the input
    //     return c_skip_input;
    // }

    // return it->second(context, prefix, size - prefix_size);
}

extern "C" int LLVMFuzzerRunDriver(int*, char***, int (*)(const uint8_t*, size_t));

static int target(const std::uint8_t* data, std::size_t size) noexcept(false)
{
    return 0;
}

int main(int argc, char** argv)
{
    fprintf(stderr, "Running main\n");
    auto result = 0;//LLVMFuzzerRunDriver(&argc, &argv, target);
    fprintf(stderr, "Result: %d\n", result);
    return result;
}