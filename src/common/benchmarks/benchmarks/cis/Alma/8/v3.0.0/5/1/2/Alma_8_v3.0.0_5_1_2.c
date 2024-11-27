#include "Alma_8_v3.0.0_5_1_2.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_5_1_2_audit(const struct benchmarks_cis_Alma_8_v3_0_0_5_1_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Alma_8_v3_0_0_5_1_2_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Alma_8_v3_0_0_5_1_2_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_1_audit(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_2_audit(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_3_audit(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_4_audit(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_5_audit(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_6_audit(&interface->rule_6, path + strlen("6") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Alma_8_v3_0_0_5_1_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_5_1_2_remediate(const struct benchmarks_cis_Alma_8_v3_0_0_5_1_2* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Alma_8_v3_0_0_5_1_2_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_Alma_8_v3_0_0_5_1_2_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "1", strlen("1")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_1_remediate(&interface->rule_1, path + strlen("1") + 1, log);
    }

    if (0 == strncmp(path + 1, "2", strlen("2")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_2_remediate(&interface->rule_2, path + strlen("2") + 1, log);
    }

    if (0 == strncmp(path + 1, "3", strlen("3")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_3_remediate(&interface->rule_3, path + strlen("3") + 1, log);
    }

    if (0 == strncmp(path + 1, "4", strlen("4")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_4_remediate(&interface->rule_4, path + strlen("4") + 1, log);
    }

    if (0 == strncmp(path + 1, "5", strlen("5")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_5_remediate(&interface->rule_5, path + strlen("5") + 1, log);
    }

    if (0 == strncmp(path + 1, "6", strlen("6")))
    {
        return benchmarks_cis_Alma_8_v3_0_0_5_1_2_6_remediate(&interface->rule_6, path + strlen("6") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_Alma_8_v3_0_0_5_1_2_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Alma_8_v3_0_0_5_1_2 benchmarks_cis_Alma_8_v3_0_0_5_1_2_init()
{
    struct benchmarks_cis_Alma_8_v3_0_0_5_1_2 result;

    result.rule_1 = benchmarks_cis_Alma_8_v3_0_0_5_1_2_1_init();
    result.rule_2 = benchmarks_cis_Alma_8_v3_0_0_5_1_2_2_init();
    result.rule_3 = benchmarks_cis_Alma_8_v3_0_0_5_1_2_3_init();
    result.rule_4 = benchmarks_cis_Alma_8_v3_0_0_5_1_2_4_init();
    result.rule_5 = benchmarks_cis_Alma_8_v3_0_0_5_1_2_5_init();
    result.rule_6 = benchmarks_cis_Alma_8_v3_0_0_5_1_2_6_init();

    return result;
}

