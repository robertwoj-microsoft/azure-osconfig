#include "CentOS.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_CentOS_audit(const struct benchmarks_cis_CentOS* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_CentOS_7_audit(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_CentOS_8_audit(&interface->rule_8, path + strlen("8") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_CentOS_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_CentOS_remediate(const struct benchmarks_cis_CentOS* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_CentOS_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_CentOS_7_remediate(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_CentOS_8_remediate(&interface->rule_8, path + strlen("8") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_CentOS_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_CentOS benchmarks_cis_CentOS_init()
{
    struct benchmarks_cis_CentOS result;

    result.rule_7 = benchmarks_cis_CentOS_7_init();
    result.rule_8 = benchmarks_cis_CentOS_8_init();

    return result;
}

