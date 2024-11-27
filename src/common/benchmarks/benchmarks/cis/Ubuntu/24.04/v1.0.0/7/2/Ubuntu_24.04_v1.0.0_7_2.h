#ifndef BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_7_2_H
#define BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_7_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_24.04_v1.0.0_7_2_1.h"
#include "10/Ubuntu_24.04_v1.0.0_7_2_10.h"
#include "2/Ubuntu_24.04_v1.0.0_7_2_2.h"
#include "3/Ubuntu_24.04_v1.0.0_7_2_3.h"
#include "4/Ubuntu_24.04_v1.0.0_7_2_4.h"
#include "5/Ubuntu_24.04_v1.0.0_7_2_5.h"
#include "6/Ubuntu_24.04_v1.0.0_7_2_6.h"
#include "7/Ubuntu_24.04_v1.0.0_7_2_7.h"
#include "8/Ubuntu_24.04_v1.0.0_7_2_8.h"
#include "9/Ubuntu_24.04_v1.0.0_7_2_9.h"

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2
{
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_1 rule_1;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_10 rule_10;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_2 rule_2;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_3 rule_3;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_4 rule_4;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_5 rule_5;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_6 rule_6;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_7 rule_7;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_8 rule_8;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_9 rule_9;
};

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2 benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_init();
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_audit(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2_remediate(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_7_2_H

