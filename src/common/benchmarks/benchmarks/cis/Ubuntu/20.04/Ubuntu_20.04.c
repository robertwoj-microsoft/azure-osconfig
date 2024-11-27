#include "Ubuntu_20.04.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_20_04_audit(const struct benchmarks_cis_Ubuntu_20_04* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v2.0.1", strlen("v2.0.1")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_audit(&interface->rule_v2_0_1, path + strlen("v2.0.1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_20_04_remediate(const struct benchmarks_cis_Ubuntu_20_04* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v2.0.1", strlen("v2.0.1")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_remediate(&interface->rule_v2_0_1, path + strlen("v2.0.1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_20_04 benchmarks_cis_Ubuntu_20_04_init()
{
    struct benchmarks_cis_Ubuntu_20_04 result;

    result.rule_v2_0_1 = benchmarks_cis_Ubuntu_20_04_v2_0_1_init();

    return result;
}

