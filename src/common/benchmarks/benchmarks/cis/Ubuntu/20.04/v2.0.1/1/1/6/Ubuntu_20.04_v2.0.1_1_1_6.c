#include "Ubuntu_20.04_v2.0.1_1_1_6.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_audit(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_4_audit(&interface->rule_4, path + strlen("4") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_remediate(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_4_remediate(&interface->rule_4, path + strlen("4") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6 benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_init()
{
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6 result;

    result.rule_2 = benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_2_init();
    result.rule_3 = benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_3_init();
    result.rule_4 = benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_4_init();

    return result;
}

