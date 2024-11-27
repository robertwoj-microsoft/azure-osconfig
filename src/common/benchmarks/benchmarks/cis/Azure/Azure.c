#include "Azure.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Azure_audit(const struct benchmarks_cis_Azure* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Azure_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Azure_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Azure_remediate(const struct benchmarks_cis_Azure* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Azure_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Azure_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Azure benchmarks_cis_Azure_init()
{
    struct benchmarks_cis_Azure result;

    result.rule_3 = benchmarks_cis_Azure_3_init();

    return result;
}

