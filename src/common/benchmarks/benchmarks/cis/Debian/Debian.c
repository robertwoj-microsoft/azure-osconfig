#include "Debian.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Debian_audit(const struct benchmarks_cis_Debian* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_Debian_10_audit(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_Debian_11_audit(&interface->rule_11, path + strlen("11") + 1, log);
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_Debian_12_audit(&interface->rule_12, path + strlen("12") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Debian_remediate(const struct benchmarks_cis_Debian* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_Debian_10_remediate(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_Debian_11_remediate(&interface->rule_11, path + strlen("11") + 1, log);
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_Debian_12_remediate(&interface->rule_12, path + strlen("12") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Debian benchmarks_cis_Debian_init()
{
    struct benchmarks_cis_Debian result;

    result.rule_10 = benchmarks_cis_Debian_10_init();
    result.rule_11 = benchmarks_cis_Debian_11_init();
    result.rule_12 = benchmarks_cis_Debian_12_init();

    return result;
}

