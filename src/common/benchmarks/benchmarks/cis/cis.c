#include "cis.h"
#include "CommonUtils.h"

benchmark_result_t benchmarks_cis_audit(const struct benchmarks_cis* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "Alma", strlen("Alma")))
    {
        return benchmarks_cis_Alma_audit(&interface->rule_Alma, path + strlen("Alma") + 1, log);
    }

    if (0 == strncmp(path + 1, "Azure", strlen("Azure")))
    {
        return benchmarks_cis_Azure_audit(&interface->rule_Azure, path + strlen("Azure") + 1, log);
    }

    if (0 == strncmp(path + 1, "CentOS", strlen("CentOS")))
    {
        return benchmarks_cis_CentOS_audit(&interface->rule_CentOS, path + strlen("CentOS") + 1, log);
    }

    if (0 == strncmp(path + 1, "Debian", strlen("Debian")))
    {
        return benchmarks_cis_Debian_audit(&interface->rule_Debian, path + strlen("Debian") + 1, log);
    }

    if (0 == strncmp(path + 1, "FreeBSD", strlen("FreeBSD")))
    {
        return benchmarks_cis_FreeBSD_audit(&interface->rule_FreeBSD, path + strlen("FreeBSD") + 1, log);
    }

    if (0 == strncmp(path + 1, "Oracle", strlen("Oracle")))
    {
        return benchmarks_cis_Oracle_audit(&interface->rule_Oracle, path + strlen("Oracle") + 1, log);
    }

    if (0 == strncmp(path + 1, "RHEL", strlen("RHEL")))
    {
        return benchmarks_cis_RHEL_audit(&interface->rule_RHEL, path + strlen("RHEL") + 1, log);
    }

    if (0 == strncmp(path + 1, "Rocky", strlen("Rocky")))
    {
        return benchmarks_cis_Rocky_audit(&interface->rule_Rocky, path + strlen("Rocky") + 1, log);
    }

    if (0 == strncmp(path + 1, "SUSE", strlen("SUSE")))
    {
        return benchmarks_cis_SUSE_audit(&interface->rule_SUSE, path + strlen("SUSE") + 1, log);
    }

    if (0 == strncmp(path + 1, "Ubuntu", strlen("Ubuntu")))
    {
        return benchmarks_cis_Ubuntu_audit(&interface->rule_Ubuntu, path + strlen("Ubuntu") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

benchmark_result_t benchmarks_cis_remediate(const struct benchmarks_cis* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if ('/' != path[0])
    {
        OsConfigLogError(log, "benchmarks_cis_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    if (0 == strncmp(path + 1, "Alma", strlen("Alma")))
    {
        return benchmarks_cis_Alma_remediate(&interface->rule_Alma, path + strlen("Alma") + 1, log);
    }

    if (0 == strncmp(path + 1, "Azure", strlen("Azure")))
    {
        return benchmarks_cis_Azure_remediate(&interface->rule_Azure, path + strlen("Azure") + 1, log);
    }

    if (0 == strncmp(path + 1, "CentOS", strlen("CentOS")))
    {
        return benchmarks_cis_CentOS_remediate(&interface->rule_CentOS, path + strlen("CentOS") + 1, log);
    }

    if (0 == strncmp(path + 1, "Debian", strlen("Debian")))
    {
        return benchmarks_cis_Debian_remediate(&interface->rule_Debian, path + strlen("Debian") + 1, log);
    }

    if (0 == strncmp(path + 1, "FreeBSD", strlen("FreeBSD")))
    {
        return benchmarks_cis_FreeBSD_remediate(&interface->rule_FreeBSD, path + strlen("FreeBSD") + 1, log);
    }

    if (0 == strncmp(path + 1, "Oracle", strlen("Oracle")))
    {
        return benchmarks_cis_Oracle_remediate(&interface->rule_Oracle, path + strlen("Oracle") + 1, log);
    }

    if (0 == strncmp(path + 1, "RHEL", strlen("RHEL")))
    {
        return benchmarks_cis_RHEL_remediate(&interface->rule_RHEL, path + strlen("RHEL") + 1, log);
    }

    if (0 == strncmp(path + 1, "Rocky", strlen("Rocky")))
    {
        return benchmarks_cis_Rocky_remediate(&interface->rule_Rocky, path + strlen("Rocky") + 1, log);
    }

    if (0 == strncmp(path + 1, "SUSE", strlen("SUSE")))
    {
        return benchmarks_cis_SUSE_remediate(&interface->rule_SUSE, path + strlen("SUSE") + 1, log);
    }

    if (0 == strncmp(path + 1, "Ubuntu", strlen("Ubuntu")))
    {
        return benchmarks_cis_Ubuntu_remediate(&interface->rule_Ubuntu, path + strlen("Ubuntu") + 1, log);
    }

    OsConfigLogError(log, "benchmarks_cis_audit: Unrecognized path: %s", path);
    return BENCHMARK_FAILED;
}

struct benchmarks_cis benchmarks_cis_init()
{
    struct benchmarks_cis result;

    result.rule_Alma = benchmarks_cis_Alma_init();
    result.rule_Azure = benchmarks_cis_Azure_init();
    result.rule_CentOS = benchmarks_cis_CentOS_init();
    result.rule_Debian = benchmarks_cis_Debian_init();
    result.rule_FreeBSD = benchmarks_cis_FreeBSD_init();
    result.rule_Oracle = benchmarks_cis_Oracle_init();
    result.rule_RHEL = benchmarks_cis_RHEL_init();
    result.rule_Rocky = benchmarks_cis_Rocky_init();
    result.rule_SUSE = benchmarks_cis_SUSE_init();
    result.rule_Ubuntu = benchmarks_cis_Ubuntu_init();

    return result;
}

