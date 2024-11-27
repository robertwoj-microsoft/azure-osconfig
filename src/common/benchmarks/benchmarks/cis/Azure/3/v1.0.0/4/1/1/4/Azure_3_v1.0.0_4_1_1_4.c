#include "Azure_3_v1.0.0_4_1_1_4.h"
#include "CommonUtils.h"

static benchmark_result_t audit(void* log)
{
    int status = -1;
    char* result = NULL;

    OsConfigLogInfo(log, "[CIS] Audit for benchmarks_cis_Azure_3_v1_0_0_4_1_1_4");
    status = ExecuteCommand(NULL, "/bin/bash /tmp/audit.sh", false, false, 1024 * 1024, 10, &result, NULL, log);
    if (0 != status || NULL == result)
    {
        OsConfigLogError(log, "Failed to execute audit.sh");
        return BENCHMARK_FAILED;
    }

    OsConfigLogInfo(log, "Audit result: %s", result);
    return BENCHMARK_COMPLIANT;
}

static benchmark_result_t remediate(void *log)
{
    // TODO: Implement remediation
    OsConfigLogInfo(log, "[CIS] Remediation for benchmarks_cis_Azure_3_v1_0_0_4_1_1_4");
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_Azure_3_v1_0_0_4_1_1_4 benchmarks_cis_Azure_3_v1_0_0_4_1_1_4_init()
{
    struct benchmarks_cis_Azure_3_v1_0_0_4_1_1_4 interface;

    interface.audit = audit;
    interface.remediate = remediate;

    return interface;
}

benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_4_1_1_4_audit(const struct benchmarks_cis_Azure_3_v1_0_0_4_1_1_4* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_3_v1_0_0_4_1_1_4_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if (0 != strcmp(path, "/audit"))
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_3_v1_0_0_4_1_1_4_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    return interface->audit(log);
}

benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_4_1_1_4_remediate(const struct benchmarks_cis_Azure_3_v1_0_0_4_1_1_4* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_3_v1_0_0_4_1_1_4_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if (0 != strcmp(path, "/remediate"))
    {
        OsConfigLogError(log, "benchmarks_cis_Azure_3_v1_0_0_4_1_1_4_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    return interface->remediate(log);
}

