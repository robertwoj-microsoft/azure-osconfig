#include "FreeBSD_14_v1.0.0_1_1_2_2.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_audit(const struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_remediate(const struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2 benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_init()
{
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2 result;

    result.rule_2 = benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_2_2_init();

    return result;
}

