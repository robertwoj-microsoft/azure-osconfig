#ifndef BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_4_2_H
#define BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_4_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/Ubuntu_22.04_v2.0.0_2_4_2_1.h"

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2
{
    struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2_1 rule_1;
};

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2 benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2_init();
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2_audit(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2_remediate(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_4_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_4_2_H

