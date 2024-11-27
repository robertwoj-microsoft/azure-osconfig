#include "Debian_11_v2.0.0_6_2_2.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_6_2_2_audit(const struct benchmarks_cis_Debian_11_v2_0_0_6_2_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_6_2_2_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_6_2_2_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_6_2_2_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_6_2_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_6_2_2_remediate(const struct benchmarks_cis_Debian_11_v2_0_0_6_2_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_6_2_2_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_6_2_2_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_6_2_2_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_6_2_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Debian_11_v2_0_0_6_2_2 benchmarks_cis_Debian_11_v2_0_0_6_2_2_init()
{
    struct benchmarks_cis_Debian_11_v2_0_0_6_2_2 result;

    result.rule_1 = benchmarks_cis_Debian_11_v2_0_0_6_2_2_1_init();

    return result;
}

