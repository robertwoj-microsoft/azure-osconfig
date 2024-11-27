#include "SUSE_15_v1.1.1_6_1.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_6_1_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_6_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_6_1_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_6_1_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_10_audit(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_11_audit(&interface->rule_11, path + strlen("11") + 1, log);
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_12_audit(&interface->rule_12, path + strlen("12") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_4_audit(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_5_audit(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_6_audit(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_7_audit(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_8_audit(&interface->rule_8, path + strlen("8") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_9_audit(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_6_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_6_1_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_6_1* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_6_1_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_6_1_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_10_remediate(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_11_remediate(&interface->rule_11, path + strlen("11") + 1, log);
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_12_remediate(&interface->rule_12, path + strlen("12") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_4_remediate(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_5_remediate(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_6_remediate(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_7_remediate(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_8_remediate(&interface->rule_8, path + strlen("8") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_SUSE_15_v1_1_1_6_1_9_remediate(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_6_1_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_SUSE_15_v1_1_1_6_1 benchmarks_cis_SUSE_15_v1_1_1_6_1_init()
{
    struct benchmarks_cis_SUSE_15_v1_1_1_6_1 result;

    result.rule_10 = benchmarks_cis_SUSE_15_v1_1_1_6_1_10_init();
    result.rule_11 = benchmarks_cis_SUSE_15_v1_1_1_6_1_11_init();
    result.rule_12 = benchmarks_cis_SUSE_15_v1_1_1_6_1_12_init();
    result.rule_2 = benchmarks_cis_SUSE_15_v1_1_1_6_1_2_init();
    result.rule_3 = benchmarks_cis_SUSE_15_v1_1_1_6_1_3_init();
    result.rule_4 = benchmarks_cis_SUSE_15_v1_1_1_6_1_4_init();
    result.rule_5 = benchmarks_cis_SUSE_15_v1_1_1_6_1_5_init();
    result.rule_6 = benchmarks_cis_SUSE_15_v1_1_1_6_1_6_init();
    result.rule_7 = benchmarks_cis_SUSE_15_v1_1_1_6_1_7_init();
    result.rule_8 = benchmarks_cis_SUSE_15_v1_1_1_6_1_8_init();
    result.rule_9 = benchmarks_cis_SUSE_15_v1_1_1_6_1_9_init();

    return result;
}

