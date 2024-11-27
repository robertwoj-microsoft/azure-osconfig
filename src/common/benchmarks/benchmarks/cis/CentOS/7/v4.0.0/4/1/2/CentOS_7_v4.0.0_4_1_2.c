#include "CentOS_7_v4.0.0_4_1_2.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_4_1_2_audit(const struct benchmarks_cis_CentOS_7_v4_0_0_4_1_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_7_v4_0_0_4_1_2_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_7_v4_0_0_4_1_2_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_CentOS_7_v4_0_0_4_1_2_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_CentOS_7_v4_0_0_4_1_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_4_1_2_remediate(const struct benchmarks_cis_CentOS_7_v4_0_0_4_1_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_7_v4_0_0_4_1_2_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_7_v4_0_0_4_1_2_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_CentOS_7_v4_0_0_4_1_2_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_CentOS_7_v4_0_0_4_1_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_CentOS_7_v4_0_0_4_1_2 benchmarks_cis_CentOS_7_v4_0_0_4_1_2_init()
{
    struct benchmarks_cis_CentOS_7_v4_0_0_4_1_2 result;

    result.rule_1 = benchmarks_cis_CentOS_7_v4_0_0_4_1_2_1_init();

    return result;
}

