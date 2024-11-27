#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_4_5_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_4_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_18.04_v2.2.0_4_5_1.h"
#include "2/Ubuntu_18.04_v2.2.0_4_5_2.h"
#include "3/Ubuntu_18.04_v2.2.0_4_5_3.h"
#include "4/Ubuntu_18.04_v2.2.0_4_5_4.h"
#include "5/Ubuntu_18.04_v2.2.0_4_5_5.h"
#include "7/Ubuntu_18.04_v2.2.0_4_5_7.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_1 rule_1;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_2 rule_2;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_3 rule_3;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_4 rule_4;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_5 rule_5;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_7 rule_7;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5 benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_4_5_H

