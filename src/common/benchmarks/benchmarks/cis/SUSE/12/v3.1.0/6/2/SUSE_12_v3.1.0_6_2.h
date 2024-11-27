#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_6_2_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_6_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_12_v3.1.0_6_2_1.h"
#include "10/SUSE_12_v3.1.0_6_2_10.h"
#include "11/SUSE_12_v3.1.0_6_2_11.h"
#include "12/SUSE_12_v3.1.0_6_2_12.h"
#include "13/SUSE_12_v3.1.0_6_2_13.h"
#include "14/SUSE_12_v3.1.0_6_2_14.h"
#include "15/SUSE_12_v3.1.0_6_2_15.h"
#include "16/SUSE_12_v3.1.0_6_2_16.h"
#include "17/SUSE_12_v3.1.0_6_2_17.h"
#include "18/SUSE_12_v3.1.0_6_2_18.h"
#include "2/SUSE_12_v3.1.0_6_2_2.h"
#include "3/SUSE_12_v3.1.0_6_2_3.h"
#include "4/SUSE_12_v3.1.0_6_2_4.h"
#include "5/SUSE_12_v3.1.0_6_2_5.h"
#include "6/SUSE_12_v3.1.0_6_2_6.h"
#include "7/SUSE_12_v3.1.0_6_2_7.h"
#include "8/SUSE_12_v3.1.0_6_2_8.h"
#include "9/SUSE_12_v3.1.0_6_2_9.h"

struct benchmarks_cis_SUSE_12_v3_1_0_6_2
{
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_1 rule_1;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_10 rule_10;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_11 rule_11;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_12 rule_12;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_13 rule_13;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_14 rule_14;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_15 rule_15;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_16 rule_16;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_17 rule_17;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_18 rule_18;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_2 rule_2;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_3 rule_3;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_4 rule_4;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_5 rule_5;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_6 rule_6;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_7 rule_7;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_8 rule_8;
    struct benchmarks_cis_SUSE_12_v3_1_0_6_2_9 rule_9;
};

struct benchmarks_cis_SUSE_12_v3_1_0_6_2 benchmarks_cis_SUSE_12_v3_1_0_6_2_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_6_2_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_6_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_6_2_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_6_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_6_2_H

