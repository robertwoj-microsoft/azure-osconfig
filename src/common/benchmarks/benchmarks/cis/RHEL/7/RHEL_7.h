#ifndef BENCHMARKS_CIS_RHEL_7_H
#define BENCHMARKS_CIS_RHEL_7_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v4.0.0/RHEL_7_v4.0.0.h"

struct benchmarks_cis_RHEL_7
{
    struct benchmarks_cis_RHEL_7_v4_0_0 rule_v4_0_0;
};

struct benchmarks_cis_RHEL_7 benchmarks_cis_RHEL_7_init();
benchmark_result_t benchmarks_cis_RHEL_7_audit(const struct benchmarks_cis_RHEL_7* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_7_remediate(const struct benchmarks_cis_RHEL_7* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_7_H

