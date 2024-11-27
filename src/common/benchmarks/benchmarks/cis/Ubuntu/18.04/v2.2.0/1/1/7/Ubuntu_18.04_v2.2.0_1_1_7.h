#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_1_1_7_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_1_1_7_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "2/Ubuntu_18.04_v2.2.0_1_1_7_2.h"
#include "3/Ubuntu_18.04_v2.2.0_1_1_7_3.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_2 rule_2;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_3 rule_3;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7 benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_7* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_1_1_7_H

