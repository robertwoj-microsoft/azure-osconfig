#include "SUSE_15.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_SUSE_15_audit(const struct benchmarks_cis_SUSE_15* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v1.1.1", strlen("v1.1.1")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_audit(&interface->rule_v1_1_1, path + strlen("v1.1.1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_15_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_SUSE_15_remediate(const struct benchmarks_cis_SUSE_15* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v1.1.1", strlen("v1.1.1")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_remediate(&interface->rule_v1_1_1, path + strlen("v1.1.1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_15_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_SUSE_15 benchmarks_cis_SUSE_15_init()
{
    struct benchmarks_cis_SUSE_15 result;

    result.rule_v1_1_1 = benchmarks_cis_SUSE_15_v1_1_1_init();

    return result;
}

