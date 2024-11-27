#include "Ubuntu_18.04_v2.2.0_1_1_7.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7 benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_init()
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7 result;

    result.rule_2 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_2_init();
    result.rule_3 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_3_init();

    return result;
}

