#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_5_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../benchmarks_common.h"

#include "1/Ubuntu_18.04_v2.2.0_5_1.h"
#include "2/Ubuntu_18.04_v2.2.0_5_2.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1 rule_1;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5_2 rule_2;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5 benchmarks_cis_Ubuntu_18_04_v2_2_0_5_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_5_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_5_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_5_H

