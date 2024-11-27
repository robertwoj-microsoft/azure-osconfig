#ifndef BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_3_4_2_10_H
#define BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_3_4_2_10_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_10
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_10 benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_10_init();
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_10_audit(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_10* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_10_remediate(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_10* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_3_4_2_10_H

