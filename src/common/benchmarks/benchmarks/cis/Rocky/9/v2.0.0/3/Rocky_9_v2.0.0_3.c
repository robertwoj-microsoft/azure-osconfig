#include "Rocky_9_v2.0.0_3.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_3_audit(const struct benchmarks_cis_Rocky_9_v2_0_0_3* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_3_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_3_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_3_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_3_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_3_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_3_remediate(const struct benchmarks_cis_Rocky_9_v2_0_0_3* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_3_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_3_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_3_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_3_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_3_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Rocky_9_v2_0_0_3 benchmarks_cis_Rocky_9_v2_0_0_3_init()
{
    struct benchmarks_cis_Rocky_9_v2_0_0_3 result;

    result.rule_1 = benchmarks_cis_Rocky_9_v2_0_0_3_1_init();
    result.rule_3 = benchmarks_cis_Rocky_9_v2_0_0_3_3_init();

    return result;
}

