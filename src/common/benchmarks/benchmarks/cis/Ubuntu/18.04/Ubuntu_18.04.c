#include "Ubuntu_18.04.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_18_04_audit(const struct benchmarks_cis_Ubuntu_18_04* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v2.2.0", strlen("v2.2.0")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_audit(&interface->rule_v2_2_0, path + strlen("v2.2.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_18_04_remediate(const struct benchmarks_cis_Ubuntu_18_04* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v2.2.0", strlen("v2.2.0")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_remediate(&interface->rule_v2_2_0, path + strlen("v2.2.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_18_04 benchmarks_cis_Ubuntu_18_04_init()
{
    struct benchmarks_cis_Ubuntu_18_04 result;

    result.rule_v2_2_0 = benchmarks_cis_Ubuntu_18_04_v2_2_0_init();

    return result;
}

