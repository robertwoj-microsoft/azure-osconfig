#ifndef BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_6_2_H
#define BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_6_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_20.04_v2.0.1_6_2_1.h"
#include "10/Ubuntu_20.04_v2.0.1_6_2_10.h"
#include "11/Ubuntu_20.04_v2.0.1_6_2_11.h"
#include "12/Ubuntu_20.04_v2.0.1_6_2_12.h"
#include "2/Ubuntu_20.04_v2.0.1_6_2_2.h"
#include "3/Ubuntu_20.04_v2.0.1_6_2_3.h"
#include "4/Ubuntu_20.04_v2.0.1_6_2_4.h"
#include "5/Ubuntu_20.04_v2.0.1_6_2_5.h"
#include "6/Ubuntu_20.04_v2.0.1_6_2_6.h"
#include "7/Ubuntu_20.04_v2.0.1_6_2_7.h"
#include "8/Ubuntu_20.04_v2.0.1_6_2_8.h"
#include "9/Ubuntu_20.04_v2.0.1_6_2_9.h"

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2
{
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_1 rule_1;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_10 rule_10;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_11 rule_11;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_12 rule_12;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_2 rule_2;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_3 rule_3;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_4 rule_4;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_5 rule_5;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_6 rule_6;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_7 rule_7;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_8 rule_8;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_9 rule_9;
};

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2 benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_init();
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_audit(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2_remediate(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_6_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_6_2_H

