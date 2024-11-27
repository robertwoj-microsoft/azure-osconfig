#ifndef BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_5_1_H
#define BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_5_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_24.04_v1.0.0_5_1_1.h"
#include "10/Ubuntu_24.04_v1.0.0_5_1_10.h"
#include "11/Ubuntu_24.04_v1.0.0_5_1_11.h"
#include "12/Ubuntu_24.04_v1.0.0_5_1_12.h"
#include "13/Ubuntu_24.04_v1.0.0_5_1_13.h"
#include "14/Ubuntu_24.04_v1.0.0_5_1_14.h"
#include "15/Ubuntu_24.04_v1.0.0_5_1_15.h"
#include "16/Ubuntu_24.04_v1.0.0_5_1_16.h"
#include "17/Ubuntu_24.04_v1.0.0_5_1_17.h"
#include "18/Ubuntu_24.04_v1.0.0_5_1_18.h"
#include "19/Ubuntu_24.04_v1.0.0_5_1_19.h"
#include "2/Ubuntu_24.04_v1.0.0_5_1_2.h"
#include "20/Ubuntu_24.04_v1.0.0_5_1_20.h"
#include "21/Ubuntu_24.04_v1.0.0_5_1_21.h"
#include "22/Ubuntu_24.04_v1.0.0_5_1_22.h"
#include "3/Ubuntu_24.04_v1.0.0_5_1_3.h"
#include "4/Ubuntu_24.04_v1.0.0_5_1_4.h"
#include "5/Ubuntu_24.04_v1.0.0_5_1_5.h"
#include "6/Ubuntu_24.04_v1.0.0_5_1_6.h"
#include "7/Ubuntu_24.04_v1.0.0_5_1_7.h"

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1
{
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_1 rule_1;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_10 rule_10;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_11 rule_11;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_12 rule_12;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_13 rule_13;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_14 rule_14;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_15 rule_15;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_16 rule_16;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_17 rule_17;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_18 rule_18;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_19 rule_19;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_2 rule_2;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_20 rule_20;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_21 rule_21;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_22 rule_22;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_3 rule_3;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_4 rule_4;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_5 rule_5;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_6 rule_6;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_7 rule_7;
};

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1 benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_init();
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_audit(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1_remediate(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_5_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_5_1_H

