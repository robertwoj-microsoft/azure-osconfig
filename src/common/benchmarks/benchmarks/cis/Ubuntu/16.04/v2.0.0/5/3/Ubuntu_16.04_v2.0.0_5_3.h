#ifndef BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_5_3_H
#define BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_5_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_16.04_v2.0.0_5_3_1.h"
#include "10/Ubuntu_16.04_v2.0.0_5_3_10.h"
#include "11/Ubuntu_16.04_v2.0.0_5_3_11.h"
#include "12/Ubuntu_16.04_v2.0.0_5_3_12.h"
#include "13/Ubuntu_16.04_v2.0.0_5_3_13.h"
#include "14/Ubuntu_16.04_v2.0.0_5_3_14.h"
#include "15/Ubuntu_16.04_v2.0.0_5_3_15.h"
#include "16/Ubuntu_16.04_v2.0.0_5_3_16.h"
#include "17/Ubuntu_16.04_v2.0.0_5_3_17.h"
#include "18/Ubuntu_16.04_v2.0.0_5_3_18.h"
#include "19/Ubuntu_16.04_v2.0.0_5_3_19.h"
#include "2/Ubuntu_16.04_v2.0.0_5_3_2.h"
#include "20/Ubuntu_16.04_v2.0.0_5_3_20.h"
#include "22/Ubuntu_16.04_v2.0.0_5_3_22.h"
#include "23/Ubuntu_16.04_v2.0.0_5_3_23.h"
#include "3/Ubuntu_16.04_v2.0.0_5_3_3.h"
#include "4/Ubuntu_16.04_v2.0.0_5_3_4.h"
#include "5/Ubuntu_16.04_v2.0.0_5_3_5.h"
#include "6/Ubuntu_16.04_v2.0.0_5_3_6.h"
#include "8/Ubuntu_16.04_v2.0.0_5_3_8.h"
#include "9/Ubuntu_16.04_v2.0.0_5_3_9.h"

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3
{
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_1 rule_1;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_10 rule_10;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_11 rule_11;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_12 rule_12;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_13 rule_13;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_14 rule_14;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_15 rule_15;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_16 rule_16;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_17 rule_17;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_18 rule_18;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_19 rule_19;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_2 rule_2;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_20 rule_20;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_22 rule_22;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_23 rule_23;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_3 rule_3;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_4 rule_4;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_5 rule_5;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_6 rule_6;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_8 rule_8;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_9 rule_9;
};

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3 benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_init();
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_audit(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_remediate(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_5_3_H

