#include "FreeBSD.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_FreeBSD_audit(const struct benchmarks_cis_FreeBSD* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "14", strlen("14")))
    {
        return benchmarks_cis_FreeBSD_14_audit(&interface->rule_14, path + strlen("14") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_FreeBSD_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_FreeBSD_remediate(const struct benchmarks_cis_FreeBSD* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_FreeBSD_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "14", strlen("14")))
    {
        return benchmarks_cis_FreeBSD_14_remediate(&interface->rule_14, path + strlen("14") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_FreeBSD_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_FreeBSD benchmarks_cis_FreeBSD_init()
{
    struct benchmarks_cis_FreeBSD result;

    result.rule_14 = benchmarks_cis_FreeBSD_14_init();

    return result;
}

