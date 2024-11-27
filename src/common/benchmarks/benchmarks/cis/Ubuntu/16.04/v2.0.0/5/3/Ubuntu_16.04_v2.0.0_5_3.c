#include "Ubuntu_16.04_v2.0.0_5_3.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_audit(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_10_audit(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_11_audit(&interface->rule_11, path + strlen("11") + 1, log);
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_12_audit(&interface->rule_12, path + strlen("12") + 1, log);
    }

    if (0 == strncmp(path + 1, "13", strlen("13")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_13_audit(&interface->rule_13, path + strlen("13") + 1, log);
    }

    if (0 == strncmp(path + 1, "14", strlen("14")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_14_audit(&interface->rule_14, path + strlen("14") + 1, log);
    }

    if (0 == strncmp(path + 1, "15", strlen("15")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_15_audit(&interface->rule_15, path + strlen("15") + 1, log);
    }

    if (0 == strncmp(path + 1, "16", strlen("16")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_16_audit(&interface->rule_16, path + strlen("16") + 1, log);
    }

    if (0 == strncmp(path + 1, "17", strlen("17")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_17_audit(&interface->rule_17, path + strlen("17") + 1, log);
    }

    if (0 == strncmp(path + 1, "18", strlen("18")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_18_audit(&interface->rule_18, path + strlen("18") + 1, log);
    }

    if (0 == strncmp(path + 1, "19", strlen("19")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_19_audit(&interface->rule_19, path + strlen("19") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "20", strlen("20")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_20_audit(&interface->rule_20, path + strlen("20") + 1, log);
    }

    if (0 == strncmp(path + 1, "22", strlen("22")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_22_audit(&interface->rule_22, path + strlen("22") + 1, log);
    }

    if (0 == strncmp(path + 1, "23", strlen("23")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_23_audit(&interface->rule_23, path + strlen("23") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_4_audit(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_5_audit(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_6_audit(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_8_audit(&interface->rule_8, path + strlen("8") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_9_audit(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_remediate(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "10", strlen("10")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_10_remediate(&interface->rule_10, path + strlen("10") + 1, log);
    }

    if (0 == strncmp(path + 1, "11", strlen("11")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_11_remediate(&interface->rule_11, path + strlen("11") + 1, log);
    }

    if (0 == strncmp(path + 1, "12", strlen("12")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_12_remediate(&interface->rule_12, path + strlen("12") + 1, log);
    }

    if (0 == strncmp(path + 1, "13", strlen("13")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_13_remediate(&interface->rule_13, path + strlen("13") + 1, log);
    }

    if (0 == strncmp(path + 1, "14", strlen("14")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_14_remediate(&interface->rule_14, path + strlen("14") + 1, log);
    }

    if (0 == strncmp(path + 1, "15", strlen("15")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_15_remediate(&interface->rule_15, path + strlen("15") + 1, log);
    }

    if (0 == strncmp(path + 1, "16", strlen("16")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_16_remediate(&interface->rule_16, path + strlen("16") + 1, log);
    }

    if (0 == strncmp(path + 1, "17", strlen("17")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_17_remediate(&interface->rule_17, path + strlen("17") + 1, log);
    }

    if (0 == strncmp(path + 1, "18", strlen("18")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_18_remediate(&interface->rule_18, path + strlen("18") + 1, log);
    }

    if (0 == strncmp(path + 1, "19", strlen("19")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_19_remediate(&interface->rule_19, path + strlen("19") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "20", strlen("20")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_20_remediate(&interface->rule_20, path + strlen("20") + 1, log);
    }

    if (0 == strncmp(path + 1, "22", strlen("22")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_22_remediate(&interface->rule_22, path + strlen("22") + 1, log);
    }

    if (0 == strncmp(path + 1, "23", strlen("23")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_23_remediate(&interface->rule_23, path + strlen("23") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_4_remediate(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_5_remediate(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_6_remediate(&interface->rule_6, path + strlen("6") + 1, log);
    }

    if (0 == strncmp(path + 1, "8", strlen("8")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_8_remediate(&interface->rule_8, path + strlen("8") + 1, log);
    }

    if (0 == strncmp(path + 1, "9", strlen("9")))
    {
        return benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_9_remediate(&interface->rule_9, path + strlen("9") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3 benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_init()
{
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3 result;

    result.rule_1 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_1_init();
    result.rule_10 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_10_init();
    result.rule_11 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_11_init();
    result.rule_12 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_12_init();
    result.rule_13 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_13_init();
    result.rule_14 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_14_init();
    result.rule_15 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_15_init();
    result.rule_16 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_16_init();
    result.rule_17 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_17_init();
    result.rule_18 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_18_init();
    result.rule_19 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_19_init();
    result.rule_2 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_2_init();
    result.rule_20 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_20_init();
    result.rule_22 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_22_init();
    result.rule_23 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_23_init();
    result.rule_3 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_3_init();
    result.rule_4 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_4_init();
    result.rule_5 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_5_init();
    result.rule_6 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_6_init();
    result.rule_8 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_8_init();
    result.rule_9 = benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_9_init();

    return result;
}

