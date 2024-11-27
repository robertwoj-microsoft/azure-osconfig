#ifndef BENCHMARKS_CIS_RHEL_7_V4_0_0_1_7_H
#define BENCHMARKS_CIS_RHEL_7_V4_0_0_1_7_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "10/RHEL_7_v4.0.0_1_7_10.h"
#include "2/RHEL_7_v4.0.0_1_7_2.h"
#include "3/RHEL_7_v4.0.0_1_7_3.h"
#include "4/RHEL_7_v4.0.0_1_7_4.h"
#include "5/RHEL_7_v4.0.0_1_7_5.h"
#include "6/RHEL_7_v4.0.0_1_7_6.h"
#include "7/RHEL_7_v4.0.0_1_7_7.h"
#include "8/RHEL_7_v4.0.0_1_7_8.h"
#include "9/RHEL_7_v4.0.0_1_7_9.h"

struct benchmarks_cis_RHEL_7_v4_0_0_1_7
{
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_10 rule_10;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_2 rule_2;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_3 rule_3;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_4 rule_4;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_5 rule_5;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_6 rule_6;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_7 rule_7;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_8 rule_8;
    struct benchmarks_cis_RHEL_7_v4_0_0_1_7_9 rule_9;
};

struct benchmarks_cis_RHEL_7_v4_0_0_1_7 benchmarks_cis_RHEL_7_v4_0_0_1_7_init();
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_1_7_audit(const struct benchmarks_cis_RHEL_7_v4_0_0_1_7* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_1_7_remediate(const struct benchmarks_cis_RHEL_7_v4_0_0_1_7* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_7_V4_0_0_1_7_H

