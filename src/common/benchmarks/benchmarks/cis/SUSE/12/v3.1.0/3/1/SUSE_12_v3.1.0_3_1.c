#include "SUSE_12_v3.1.0_3_1.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_3_1_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_3_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_3_1_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_3_1_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_3_1_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_3_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_3_1_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_3_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_3_1_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_3_1_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_3_1_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_3_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_SUSE_12_v3_1_0_3_1 benchmarks_cis_SUSE_12_v3_1_0_3_1_init()
{
    struct benchmarks_cis_SUSE_12_v3_1_0_3_1 result;

    result.rule_2 = benchmarks_cis_SUSE_12_v3_1_0_3_1_2_init();

    return result;
}

