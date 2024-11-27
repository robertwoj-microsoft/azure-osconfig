#include "RHEL_9_v2.0.0_2_4_1.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_2_4_1_audit(const struct benchmarks_cis_RHEL_9_v2_0_0_2_4_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_9_v2_0_0_2_4_1_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_9_v2_0_0_2_4_1_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_4_audit(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_5_audit(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_6_audit(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_7_audit(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_8_audit(&interface->rule_8, path + strlen("8") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_RHEL_9_v2_0_0_2_4_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_2_4_1_remediate(const struct benchmarks_cis_RHEL_9_v2_0_0_2_4_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_9_v2_0_0_2_4_1_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_RHEL_9_v2_0_0_2_4_1_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_4_remediate(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_5_remediate(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_6_remediate(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_7_remediate(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_RHEL_9_v2_0_0_2_4_1_8_remediate(&interface->rule_8, path + strlen("8") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_RHEL_9_v2_0_0_2_4_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_RHEL_9_v2_0_0_2_4_1 benchmarks_cis_RHEL_9_v2_0_0_2_4_1_init()
{
    struct benchmarks_cis_RHEL_9_v2_0_0_2_4_1 result;

    result.rule_1 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_1_init();
    result.rule_2 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_2_init();
    result.rule_3 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_3_init();
    result.rule_4 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_4_init();
    result.rule_5 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_5_init();
    result.rule_6 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_6_init();
    result.rule_7 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_7_init();
    result.rule_8 = benchmarks_cis_RHEL_9_v2_0_0_2_4_1_8_init();

    return result;
}

