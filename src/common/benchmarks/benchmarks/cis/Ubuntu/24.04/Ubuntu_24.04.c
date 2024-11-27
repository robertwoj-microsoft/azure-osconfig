#include "Ubuntu_24.04.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_24_04_audit(const struct benchmarks_cis_Ubuntu_24_04* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v1.0.0", strlen("v1.0.0")))
    {
        return benchmarks_cis_Ubuntu_24_04_v1_0_0_audit(&interface->rule_v1_0_0, path + strlen("v1.0.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_24_04_remediate(const struct benchmarks_cis_Ubuntu_24_04* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v1.0.0", strlen("v1.0.0")))
    {
        return benchmarks_cis_Ubuntu_24_04_v1_0_0_remediate(&interface->rule_v1_0_0, path + strlen("v1.0.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_24_04 benchmarks_cis_Ubuntu_24_04_init()
{
    struct benchmarks_cis_Ubuntu_24_04 result;

    result.rule_v1_0_0 = benchmarks_cis_Ubuntu_24_04_v1_0_0_init();

    return result;
}

