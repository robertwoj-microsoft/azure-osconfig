#ifndef BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_1_15_H
#define BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_1_15_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15 benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15_init();
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15_audit(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15_remediate(const struct benchmarks_cis_Ubuntu_22_04_v2_0_0_2_1_15* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_22_04_V2_0_0_2_1_15_H

