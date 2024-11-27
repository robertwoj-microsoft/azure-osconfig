#ifndef BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_1_H
#define BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_22.04_v2.0.0_2_1_1.h"
#include "10/Ubuntu_22.04_v2.0.0_2_1_10.h"
#include "11/Ubuntu_22.04_v2.0.0_2_1_11.h"
#include "12/Ubuntu_22.04_v2.0.0_2_1_12.h"
#include "13/Ubuntu_22.04_v2.0.0_2_1_13.h"
#include "14/Ubuntu_22.04_v2.0.0_2_1_14.h"
#include "15/Ubuntu_22.04_v2.0.0_2_1_15.h"
#include "16/Ubuntu_22.04_v2.0.0_2_1_16.h"
#include "17/Ubuntu_22.04_v2.0.0_2_1_17.h"
#include "18/Ubuntu_22.04_v2.0.0_2_1_18.h"
#include "19/Ubuntu_22.04_v2.0.0_2_1_19.h"
#include "2/Ubuntu_22.04_v2.0.0_2_1_2.h"
#include "21/Ubuntu_22.04_v2.0.0_2_1_21.h"
#include "22/Ubuntu_22.04_v2.0.0_2_1_22.h"
#include "3/Ubuntu_22.04_v2.0.0_2_1_3.h"
#include "4/Ubuntu_22.04_v2.0.0_2_1_4.h"
#include "5/Ubuntu_22.04_v2.0.0_2_1_5.h"
#include "6/Ubuntu_22.04_v2.0.0_2_1_6.h"
#include "7/Ubuntu_22.04_v2.0.0_2_1_7.h"
#include "8/Ubuntu_22.04_v2.0.0_2_1_8.h"
#include "9/Ubuntu_22.04_v2.0.0_2_1_9.h"

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1
{
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_1 rule_1;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_10 rule_10;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_11 rule_11;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_12 rule_12;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_13 rule_13;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_14 rule_14;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15 rule_15;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_16 rule_16;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_17 rule_17;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_18 rule_18;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_19 rule_19;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_2 rule_2;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_21 rule_21;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_22 rule_22;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_3 rule_3;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_4 rule_4;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_5 rule_5;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_6 rule_6;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_7 rule_7;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_8 rule_8;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_9 rule_9;
};

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1 benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_init();
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_audit(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_remediate(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_1_H

