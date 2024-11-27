#include "SUSE_15_v1.1.1_2_2_14.h"
#include "CommonUtils.h"

static benchmark_result_t audit(void* log)
{
    int status = -1;
    char* result = NULL;

    OsConfigLogInfo(log, "[CIS] Audit for benchmarks_cis_SUSE_15_v1_1_1_2_2_14");
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
    OsConfigLogInfo(log, "[CIS] Remediation for benchmarks_cis_SUSE_15_v1_1_1_2_2_14");
    return BENCHMARK_FAILED;
}

struct benchmarks_cis_SUSE_15_v1_1_1_2_2_14 benchmarks_cis_SUSE_15_v1_1_1_2_2_14_init()
{
    struct benchmarks_cis_SUSE_15_v1_1_1_2_2_14 interface;

    interface.audit = audit;
    interface.remediate = remediate;

    return interface;
}

benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_2_2_14_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_2_2_14* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_2_2_14_audit: NULL argument");
        return BENCHMARK_FAILED;
    }

    if (0 != strcmp(path, "/audit"))
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_2_2_14_audit: Invalid path");
        return BENCHMARK_FAILED;
    }

    return interface->audit(log);
}

benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_2_2_14_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_2_2_14* interface, const char* path, void* log)
{
    if (NULL == interface || NULL == path)
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_2_2_14_remediate: NULL argument");
        return BENCHMARK_FAILED;
    }

    if (0 != strcmp(path, "/remediate"))
    {
        OsConfigLogError(log, "benchmarks_cis_SUSE_15_v1_1_1_2_2_14_remediate: Invalid path");
        return BENCHMARK_FAILED;
    }

    return interface->remediate(log);
}

