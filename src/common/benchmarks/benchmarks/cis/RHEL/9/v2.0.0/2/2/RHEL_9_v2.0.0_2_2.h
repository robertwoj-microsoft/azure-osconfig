#ifndef BENCHMARKS_CIS_RHEL_9_V2_0_0_2_2_H
#define BENCHMARKS_CIS_RHEL_9_V2_0_0_2_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/RHEL_9_v2.0.0_2_2_1.h"
#include "3/RHEL_9_v2.0.0_2_2_3.h"
#include "4/RHEL_9_v2.0.0_2_2_4.h"
#include "5/RHEL_9_v2.0.0_2_2_5.h"

struct benchmarks_cis_RHEL_9_v2_0_0_2_2
{
    struct benchmarks_cis_RHEL_9_v2_0_0_2_2_1 rule_1;
    struct benchmarks_cis_RHEL_9_v2_0_0_2_2_3 rule_3;
    struct benchmarks_cis_RHEL_9_v2_0_0_2_2_4 rule_4;
    struct benchmarks_cis_RHEL_9_v2_0_0_2_2_5 rule_5;
};

struct benchmarks_cis_RHEL_9_v2_0_0_2_2 benchmarks_cis_RHEL_9_v2_0_0_2_2_init();
benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_2_2_audit(const struct benchmarks_cis_RHEL_9_v2_0_0_2_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_2_2_remediate(const struct benchmarks_cis_RHEL_9_v2_0_0_2_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_9_V2_0_0_2_2_H

