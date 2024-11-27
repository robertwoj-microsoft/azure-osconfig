#include "SUSE.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_SUSE_audit(const struct benchmarks_cis_SUSE* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_SUSE_12_audit(&interface->rule_12, path + strlen("12") + 1, log);
    }

    if (0 == strncmp(path + 1, "15", strlen("15")))
    {
        return benchmarks_cis_SUSE_15_audit(&interface->rule_15, path + strlen("15") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_SUSE_remediate(const struct benchmarks_cis_SUSE* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_SUSE_12_remediate(&interface->rule_12, path + strlen("12") + 1, log);
    }

    if (0 == strncmp(path + 1, "15", strlen("15")))
    {
        return benchmarks_cis_SUSE_15_remediate(&interface->rule_15, path + strlen("15") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_SUSE benchmarks_cis_SUSE_init()
{
    struct benchmarks_cis_SUSE result;

    result.rule_12 = benchmarks_cis_SUSE_12_init();
    result.rule_15 = benchmarks_cis_SUSE_15_init();

    return result;
}

