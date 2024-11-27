#ifndef BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_1_4_3_H
#define BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_1_4_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_4_3
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_4_3 benchmarks_cis_Ubuntu_16_04_v2_0_0_1_4_3_init();
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_1_4_3_audit(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_4_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_1_4_3_remediate(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_4_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_1_4_3_H

