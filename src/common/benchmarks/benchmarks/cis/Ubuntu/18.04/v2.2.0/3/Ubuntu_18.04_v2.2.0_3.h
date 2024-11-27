#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_3_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../benchmarks_common.h"

#include "1/Ubuntu_18.04_v2.2.0_3_1.h"
#include "3/Ubuntu_18.04_v2.2.0_3_3.h"
#include "4/Ubuntu_18.04_v2.2.0_3_4.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_3
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_3_1 rule_1;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_3_3 rule_3;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_3_4 rule_4;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_3 benchmarks_cis_Ubuntu_18_04_v2_2_0_3_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_3_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_3_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_3_H

