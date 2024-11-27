#include "Rocky_9.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Rocky_9_audit(const struct benchmarks_cis_Rocky_9* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v2.0.0", strlen("v2.0.0")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_audit(&interface->rule_v2_0_0, path + strlen("v2.0.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Rocky_9_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Rocky_9_remediate(const struct benchmarks_cis_Rocky_9* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v2.0.0", strlen("v2.0.0")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_remediate(&interface->rule_v2_0_0, path + strlen("v2.0.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Rocky_9_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Rocky_9 benchmarks_cis_Rocky_9_init()
{
    struct benchmarks_cis_Rocky_9 result;

    result.rule_v2_0_0 = benchmarks_cis_Rocky_9_v2_0_0_init();

    return result;
}

