#include "Ubuntu_24.04_v1.0.0_6_1_4.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_audit(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_remediate(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4 benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_init()
{
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4 result;

    result.rule_1 = benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_1_init();

    return result;
}

