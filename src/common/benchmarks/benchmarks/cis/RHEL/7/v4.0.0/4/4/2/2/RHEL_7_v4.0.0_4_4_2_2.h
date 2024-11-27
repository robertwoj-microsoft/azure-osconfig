#ifndef BENCHMARKS_CIS_RHEL_7_V4_0_0_4_4_2_2_H
#define BENCHMARKS_CIS_RHEL_7_V4_0_0_4_4_2_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "1/RHEL_7_v4.0.0_4_4_2_2_1.h"
#include "2/RHEL_7_v4.0.0_4_4_2_2_2.h"
#include "3/RHEL_7_v4.0.0_4_4_2_2_3.h"
#include "4/RHEL_7_v4.0.0_4_4_2_2_4.h"
#include "5/RHEL_7_v4.0.0_4_4_2_2_5.h"
#include "6/RHEL_7_v4.0.0_4_4_2_2_6.h"
#include "7/RHEL_7_v4.0.0_4_4_2_2_7.h"

struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2
{
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_1 rule_1;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_2 rule_2;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_3 rule_3;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_4 rule_4;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_5 rule_5;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_6 rule_6;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_7 rule_7;
};

struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2 benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_init();
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_audit(const struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2_remediate(const struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_7_V4_0_0_4_4_2_2_H

