#ifndef BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_4_2_H
#define BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_4_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_20.04_v2.0.1_4_2_1.h"
#include "10/Ubuntu_20.04_v2.0.1_4_2_10.h"
#include "11/Ubuntu_20.04_v2.0.1_4_2_11.h"
#include "13/Ubuntu_20.04_v2.0.1_4_2_13.h"
#include "14/Ubuntu_20.04_v2.0.1_4_2_14.h"
#include "15/Ubuntu_20.04_v2.0.1_4_2_15.h"
#include "17/Ubuntu_20.04_v2.0.1_4_2_17.h"
#include "18/Ubuntu_20.04_v2.0.1_4_2_18.h"
#include "19/Ubuntu_20.04_v2.0.1_4_2_19.h"
#include "2/Ubuntu_20.04_v2.0.1_4_2_2.h"
#include "20/Ubuntu_20.04_v2.0.1_4_2_20.h"
#include "21/Ubuntu_20.04_v2.0.1_4_2_21.h"
#include "22/Ubuntu_20.04_v2.0.1_4_2_22.h"
#include "3/Ubuntu_20.04_v2.0.1_4_2_3.h"
#include "4/Ubuntu_20.04_v2.0.1_4_2_4.h"
#include "5/Ubuntu_20.04_v2.0.1_4_2_5.h"
#include "6/Ubuntu_20.04_v2.0.1_4_2_6.h"
#include "7/Ubuntu_20.04_v2.0.1_4_2_7.h"
#include "8/Ubuntu_20.04_v2.0.1_4_2_8.h"
#include "9/Ubuntu_20.04_v2.0.1_4_2_9.h"

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2
{
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_1 rule_1;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_10 rule_10;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_11 rule_11;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_13 rule_13;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_14 rule_14;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_15 rule_15;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_17 rule_17;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_18 rule_18;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_19 rule_19;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_2 rule_2;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_20 rule_20;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_21 rule_21;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_22 rule_22;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_3 rule_3;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_4 rule_4;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_5 rule_5;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_6 rule_6;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_7 rule_7;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_8 rule_8;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_9 rule_9;
};

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2 benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_init();
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_audit(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2_remediate(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_4_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_4_2_H

