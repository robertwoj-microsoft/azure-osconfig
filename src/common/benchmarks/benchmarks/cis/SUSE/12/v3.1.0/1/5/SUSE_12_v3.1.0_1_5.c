#include "SUSE_12_v3.1.0_1_5.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_1_5_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_1_5* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_5_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_5_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_5_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_5_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_5_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_5_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_1_5_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_1_5* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_5_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_5_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_5_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_5_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_SUSE_12_v3_1_0_1_5_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_12_v3_1_0_1_5_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_SUSE_12_v3_1_0_1_5 benchmarks_cis_SUSE_12_v3_1_0_1_5_init()
{
    struct benchmarks_cis_SUSE_12_v3_1_0_1_5 result;

    result.rule_1 = benchmarks_cis_SUSE_12_v3_1_0_1_5_1_init();
    result.rule_2 = benchmarks_cis_SUSE_12_v3_1_0_1_5_2_init();
    result.rule_3 = benchmarks_cis_SUSE_12_v3_1_0_1_5_3_init();

    return result;
}

