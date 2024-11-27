#include "Debian_10_v2.0.0_5_2.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_5_2_audit(const struct benchmarks_cis_Debian_10_v2_0_0_5_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_10_v2_0_0_5_2_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_10_v2_0_0_5_2_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Debian_10_v2_0_0_5_2_4_audit(&interface->rule_4, path + strlen("4") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_10_v2_0_0_5_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_5_2_remediate(const struct benchmarks_cis_Debian_10_v2_0_0_5_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_10_v2_0_0_5_2_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_10_v2_0_0_5_2_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Debian_10_v2_0_0_5_2_4_remediate(&interface->rule_4, path + strlen("4") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_10_v2_0_0_5_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Debian_10_v2_0_0_5_2 benchmarks_cis_Debian_10_v2_0_0_5_2_init()
{
    struct benchmarks_cis_Debian_10_v2_0_0_5_2 result;

    result.rule_4 = benchmarks_cis_Debian_10_v2_0_0_5_2_4_init();

    return result;
}

