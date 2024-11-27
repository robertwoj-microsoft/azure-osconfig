#include "Ubuntu_18.04_v2.2.0_1_8.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_10_audit(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_4_audit(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_5_audit(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_6_audit(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_7_audit(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_8_audit(&interface->rule_8, path + strlen("8") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_9_audit(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_10_remediate(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_4_remediate(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_5_remediate(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_6_remediate(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "7", strlen("7")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_7_remediate(&interface->rule_7, path + strlen("7") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_8_remediate(&interface->rule_8, path + strlen("8") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_9_remediate(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8 benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_init()
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8 result;

    result.rule_10 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_10_init();
    result.rule_2 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_2_init();
    result.rule_3 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_3_init();
    result.rule_4 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_4_init();
    result.rule_5 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_5_init();
    result.rule_6 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_6_init();
    result.rule_7 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_7_init();
    result.rule_8 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_8_init();
    result.rule_9 = benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_9_init();

    return result;
}

