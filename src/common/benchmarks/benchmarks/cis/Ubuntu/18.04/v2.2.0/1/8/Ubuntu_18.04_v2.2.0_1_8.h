#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_1_8_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_1_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "10/Ubuntu_18.04_v2.2.0_1_8_10.h"
#include "2/Ubuntu_18.04_v2.2.0_1_8_2.h"
#include "3/Ubuntu_18.04_v2.2.0_1_8_3.h"
#include "4/Ubuntu_18.04_v2.2.0_1_8_4.h"
#include "5/Ubuntu_18.04_v2.2.0_1_8_5.h"
#include "6/Ubuntu_18.04_v2.2.0_1_8_6.h"
#include "7/Ubuntu_18.04_v2.2.0_1_8_7.h"
#include "8/Ubuntu_18.04_v2.2.0_1_8_8.h"
#include "9/Ubuntu_18.04_v2.2.0_1_8_9.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_10 rule_10;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_2 rule_2;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_3 rule_3;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_4 rule_4;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_5 rule_5;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_6 rule_6;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_7 rule_7;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_8 rule_8;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_9 rule_9;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8 benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_1_8_H

