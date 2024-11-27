#ifndef BENCHMARKS_CIS_RHEL_7_V4_0_0_4_5_2_H
#define BENCHMARKS_CIS_RHEL_7_V4_0_0_4_5_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/RHEL_7_v4.0.0_4_5_2_1.h"
#include "2/RHEL_7_v4.0.0_4_5_2_2.h"
#include "3/RHEL_7_v4.0.0_4_5_2_3.h"
#include "4/RHEL_7_v4.0.0_4_5_2_4.h"

struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2
{
    struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2_1 rule_1;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2_2 rule_2;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2_3 rule_3;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2_4 rule_4;
};

struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2 benchmarks_cis_RHEL_7_v4_0_0_4_5_2_init();
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_4_5_2_audit(const struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_4_5_2_remediate(const struct benchmarks_cis_RHEL_7_v4_0_0_4_5_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_7_V4_0_0_4_5_2_H

