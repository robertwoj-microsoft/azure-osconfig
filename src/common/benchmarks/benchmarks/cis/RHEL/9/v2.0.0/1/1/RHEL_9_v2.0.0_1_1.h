#ifndef BENCHMARKS_CIS_RHEL_9_V2_0_0_1_1_H
#define BENCHMARKS_CIS_RHEL_9_V2_0_0_1_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/RHEL_9_v2.0.0_1_1_1.h"
#include "2/RHEL_9_v2.0.0_1_1_2.h"

struct benchmarks_cis_RHEL_9_v2_0_0_1_1
{
    struct benchmarks_cis_RHEL_9_v2_0_0_1_1_1 rule_1;
    struct benchmarks_cis_RHEL_9_v2_0_0_1_1_2 rule_2;
};

struct benchmarks_cis_RHEL_9_v2_0_0_1_1 benchmarks_cis_RHEL_9_v2_0_0_1_1_init();
benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_1_1_audit(const struct benchmarks_cis_RHEL_9_v2_0_0_1_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_1_1_remediate(const struct benchmarks_cis_RHEL_9_v2_0_0_1_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_9_V2_0_0_1_1_H

