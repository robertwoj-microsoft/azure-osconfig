#ifndef BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_5_2_H
#define BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_5_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "4/Ubuntu_20.04_v2.0.1_5_2_4.h"

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2
{
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4 rule_4;
};

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2 benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_init();
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_audit(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_remediate(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_5_2_H

