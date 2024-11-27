#ifndef BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_5_1_H
#define BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_5_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_16.04_v2.0.0_5_1_1.h"
#include "2/Ubuntu_16.04_v2.0.0_5_1_2.h"
#include "3/Ubuntu_16.04_v2.0.0_5_1_3.h"
#include "4/Ubuntu_16.04_v2.0.0_5_1_4.h"
#include "5/Ubuntu_16.04_v2.0.0_5_1_5.h"
#include "6/Ubuntu_16.04_v2.0.0_5_1_6.h"
#include "7/Ubuntu_16.04_v2.0.0_5_1_7.h"
#include "8/Ubuntu_16.04_v2.0.0_5_1_8.h"
#include "9/Ubuntu_16.04_v2.0.0_5_1_9.h"

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1
{
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_1 rule_1;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_2 rule_2;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_3 rule_3;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_4 rule_4;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_5 rule_5;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_6 rule_6;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_7 rule_7;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_8 rule_8;
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_9 rule_9;
};

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1 benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_init();
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_audit(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1_remediate(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_5_1_H

