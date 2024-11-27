#include "SUSE_12_v3.1.0_1_7.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_1_7_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_1_7* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_7_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_7_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_7_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_7_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_1_7_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_1_7* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_7_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_7_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_7_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_7_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_SUSE_12_v3_1_0_1_7 benchmarks_cis_SUSE_12_v3_1_0_1_7_init()
{
    struct benchmarks_cis_SUSE_12_v3_1_0_1_7 result;

    result.rule_1 = benchmarks_cis_SUSE_12_v3_1_0_1_7_1_init();

    return result;
}

