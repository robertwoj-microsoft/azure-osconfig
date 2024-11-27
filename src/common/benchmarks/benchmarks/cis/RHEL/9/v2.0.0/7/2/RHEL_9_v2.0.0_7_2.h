#ifndef BENCHMARKS_CIS_RHEL_9_V2_0_0_7_2_H
#define BENCHMARKS_CIS_RHEL_9_V2_0_0_7_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/RHEL_9_v2.0.0_7_2_1.h"
#include "2/RHEL_9_v2.0.0_7_2_2.h"
#include "3/RHEL_9_v2.0.0_7_2_3.h"
#include "4/RHEL_9_v2.0.0_7_2_4.h"
#include "5/RHEL_9_v2.0.0_7_2_5.h"
#include "6/RHEL_9_v2.0.0_7_2_6.h"
#include "7/RHEL_9_v2.0.0_7_2_7.h"
#include "8/RHEL_9_v2.0.0_7_2_8.h"
#include "9/RHEL_9_v2.0.0_7_2_9.h"

struct benchmarks_cis_RHEL_9_v2_0_0_7_2
{
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_1 rule_1;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_2 rule_2;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_3 rule_3;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_4 rule_4;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_5 rule_5;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_6 rule_6;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_7 rule_7;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_8 rule_8;
    struct benchmarks_cis_RHEL_9_v2_0_0_7_2_9 rule_9;
};

struct benchmarks_cis_RHEL_9_v2_0_0_7_2 benchmarks_cis_RHEL_9_v2_0_0_7_2_init();
benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_7_2_audit(const struct benchmarks_cis_RHEL_9_v2_0_0_7_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_9_v2_0_0_7_2_remediate(const struct benchmarks_cis_RHEL_9_v2_0_0_7_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_9_V2_0_0_7_2_H

