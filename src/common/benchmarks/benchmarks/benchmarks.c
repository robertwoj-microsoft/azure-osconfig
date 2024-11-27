#include "benchmarks.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_audit(const struct benchmarks* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "cis", strlen("cis")))
    {
        return benchmarks_cis_audit(&interface->rule_cis, path + strlen("cis") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_remediate(const struct benchmarks* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "cis", strlen("cis")))
    {
        return benchmarks_cis_remediate(&interface->rule_cis, path + strlen("cis") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks benchmarks_init()
{
    struct benchmarks result;

    result.rule_cis = benchmarks_cis_init();

    return result;
}

