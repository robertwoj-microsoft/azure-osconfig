#include "Debian_11_v2.0.0_5_2.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_5_2_audit(const struct benchmarks_cis_Debian_11_v2_0_0_5_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_5_2_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_5_2_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_5_audit(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_6_audit(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_7_audit(&interface->rule_7, path + strlen("7") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_5_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_5_2_remediate(const struct benchmarks_cis_Debian_11_v2_0_0_5_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_5_2_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_5_2_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_5_remediate(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_6_remediate(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_Debian_11_v2_0_0_5_2_7_remediate(&interface->rule_7, path + strlen("7") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Debian_11_v2_0_0_5_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Debian_11_v2_0_0_5_2 benchmarks_cis_Debian_11_v2_0_0_5_2_init()
{
    struct benchmarks_cis_Debian_11_v2_0_0_5_2 result;

    result.rule_1 = benchmarks_cis_Debian_11_v2_0_0_5_2_1_init();
    result.rule_2 = benchmarks_cis_Debian_11_v2_0_0_5_2_2_init();
    result.rule_3 = benchmarks_cis_Debian_11_v2_0_0_5_2_3_init();
    result.rule_5 = benchmarks_cis_Debian_11_v2_0_0_5_2_5_init();
    result.rule_6 = benchmarks_cis_Debian_11_v2_0_0_5_2_6_init();
    result.rule_7 = benchmarks_cis_Debian_11_v2_0_0_5_2_7_init();

    return result;
}

