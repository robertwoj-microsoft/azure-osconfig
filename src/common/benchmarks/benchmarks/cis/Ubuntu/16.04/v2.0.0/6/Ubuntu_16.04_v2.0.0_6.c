#include "Ubuntu_16.04_v2.0.0_6.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_6_audit(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_6* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_6_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_6_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_6_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_6_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_6_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_6_remediate(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_6* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_6_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_6_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_6_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_6_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_6_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_6 benchmarks_cis_Ubuntu_16_04_v2_0_0_6_init()
{
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_6 result;

    result.rule_1 = benchmarks_cis_Ubuntu_16_04_v2_0_0_6_1_init();
    result.rule_2 = benchmarks_cis_Ubuntu_16_04_v2_0_0_6_2_init();

    return result;
}

