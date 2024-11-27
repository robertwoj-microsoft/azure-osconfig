#include "Rocky_9_v2.0.0_7.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_7_audit(const struct benchmarks_cis_Rocky_9_v2_0_0_7* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_7_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_7_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_7_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_7_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_7_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_7_remediate(const struct benchmarks_cis_Rocky_9_v2_0_0_7* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_7_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_7_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_7_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Rocky_9_v2_0_0_7_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Rocky_9_v2_0_0_7_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Rocky_9_v2_0_0_7 benchmarks_cis_Rocky_9_v2_0_0_7_init()
{
    struct benchmarks_cis_Rocky_9_v2_0_0_7 result;

    result.rule_1 = benchmarks_cis_Rocky_9_v2_0_0_7_1_init();
    result.rule_2 = benchmarks_cis_Rocky_9_v2_0_0_7_2_init();

    return result;
}

