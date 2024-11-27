#include "Ubuntu_20.04_v2.0.1_5_2_4.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_audit(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_11_audit(&interface->rule_11, path + strlen("11") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_remediate(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_11_remediate(&interface->rule_11, path + strlen("11") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4 benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_init()
{
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4 result;

    result.rule_11 = benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_11_init();

    return result;
}

