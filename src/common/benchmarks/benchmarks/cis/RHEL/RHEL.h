#ifndef BENCHMARKS_CIS_RHEL_H
#define BENCHMARKS_CIS_RHEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "7/RHEL_7.h"
#include "9/RHEL_9.h"

struct benchmarks_cis_RHEL
{
    struct benchmarks_cis_RHEL_7 rule_7;
    struct benchmarks_cis_RHEL_9 rule_9;
};

struct benchmarks_cis_RHEL benchmarks_cis_RHEL_init();
benchmark_result_t benchmarks_cis_RHEL_audit(const struct benchmarks_cis_RHEL* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_remediate(const struct benchmarks_cis_RHEL* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_H

