#include "Ubuntu.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_audit(const struct benchmarks_cis_Ubuntu* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "16.04", strlen("16.04")))
    {
        return benchmarks_cis_Ubuntu_16_04_audit(&interface->rule_16_04, path + strlen("16.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "18.04", strlen("18.04")))
    {
        return benchmarks_cis_Ubuntu_18_04_audit(&interface->rule_18_04, path + strlen("18.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "20.04", strlen("20.04")))
    {
        return benchmarks_cis_Ubuntu_20_04_audit(&interface->rule_20_04, path + strlen("20.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "22.04", strlen("22.04")))
    {
        return benchmarks_cis_Ubuntu_22_04_audit(&interface->rule_22_04, path + strlen("22.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "24.04", strlen("24.04")))
    {
        return benchmarks_cis_Ubuntu_24_04_audit(&interface->rule_24_04, path + strlen("24.04") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_remediate(const struct benchmarks_cis_Ubuntu* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "16.04", strlen("16.04")))
    {
        return benchmarks_cis_Ubuntu_16_04_remediate(&interface->rule_16_04, path + strlen("16.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "18.04", strlen("18.04")))
    {
        return benchmarks_cis_Ubuntu_18_04_remediate(&interface->rule_18_04, path + strlen("18.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "20.04", strlen("20.04")))
    {
        return benchmarks_cis_Ubuntu_20_04_remediate(&interface->rule_20_04, path + strlen("20.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "22.04", strlen("22.04")))
    {
        return benchmarks_cis_Ubuntu_22_04_remediate(&interface->rule_22_04, path + strlen("22.04") + 1, log);
    }

    if (0 == strncmp(path + 1, "24.04", strlen("24.04")))
    {
        return benchmarks_cis_Ubuntu_24_04_remediate(&interface->rule_24_04, path + strlen("24.04") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu benchmarks_cis_Ubuntu_init()
{
    struct benchmarks_cis_Ubuntu result;

    result.rule_16_04 = benchmarks_cis_Ubuntu_16_04_init();
    result.rule_18_04 = benchmarks_cis_Ubuntu_18_04_init();
    result.rule_20_04 = benchmarks_cis_Ubuntu_20_04_init();
    result.rule_22_04 = benchmarks_cis_Ubuntu_22_04_init();
    result.rule_24_04 = benchmarks_cis_Ubuntu_24_04_init();

    return result;
}

