#include "Debian_12.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Debian_12_audit(const struct benchmarks_cis_Debian_12* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_12_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_12_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v1.1.0", strlen("v1.1.0")))
    {
        return benchmarks_cis_Debian_12_v1_1_0_audit(&interface->rule_v1_1_0, path + strlen("v1.1.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_12_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Debian_12_remediate(const struct benchmarks_cis_Debian_12* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_12_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_12_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "v1.1.0", strlen("v1.1.0")))
    {
        return benchmarks_cis_Debian_12_v1_1_0_remediate(&interface->rule_v1_1_0, path + strlen("v1.1.0") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_12_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Debian_12 benchmarks_cis_Debian_12_init()
{
    struct benchmarks_cis_Debian_12 result;

    result.rule_v1_1_0 = benchmarks_cis_Debian_12_v1_1_0_init();

    return result;
}

