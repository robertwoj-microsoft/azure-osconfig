#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_5_1_2_5_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_5_1_2_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1_2_5
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1_2_5 benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1_2_5_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1_2_5_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1_2_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1_2_5_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_5_1_2_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_5_1_2_5_H

