#ifndef BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_1_1_2_3_H
#define BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_1_1_2_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "2/Ubuntu_22.04_v2.0.0_1_1_2_3_2.h"
#include "3/Ubuntu_22.04_v2.0.0_1_1_2_3_3.h"

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3
{
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3_2 rule_2;
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3_3 rule_3;
};

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3 benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3_init();
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3_audit(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3_remediate(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_1_1_2_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_1_1_2_3_H

