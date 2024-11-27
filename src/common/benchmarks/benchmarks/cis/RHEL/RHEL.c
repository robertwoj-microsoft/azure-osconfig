#include "RHEL.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_RHEL_audit(const struct benchmarks_cis_RHEL* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_RHEL_7_audit(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_RHEL_9_audit(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_RHEL_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_RHEL_remediate(const struct benchmarks_cis_RHEL* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_RHEL_7_remediate(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_RHEL_9_remediate(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_RHEL_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_RHEL benchmarks_cis_RHEL_init()
{
    struct benchmarks_cis_RHEL result;

    result.rule_7 = benchmarks_cis_RHEL_7_init();
    result.rule_9 = benchmarks_cis_RHEL_9_init();

    return result;
}

