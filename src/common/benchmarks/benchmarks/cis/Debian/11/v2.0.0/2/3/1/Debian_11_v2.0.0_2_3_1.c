#include "Debian_11_v2.0.0_2_3_1.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_2_3_1_audit(const struct benchmarks_cis_Debian_11_v2_0_0_2_3_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_2_3_1_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_2_3_1_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_2_3_1_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_2_3_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_2_3_1_remediate(const struct benchmarks_cis_Debian_11_v2_0_0_2_3_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_2_3_1_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_2_3_1_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_2_3_1_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_2_3_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Debian_11_v2_0_0_2_3_1 benchmarks_cis_Debian_11_v2_0_0_2_3_1_init()
{
    struct benchmarks_cis_Debian_11_v2_0_0_2_3_1 result;

    result.rule_1 = benchmarks_cis_Debian_11_v2_0_0_2_3_1_1_init();

    return result;
}

