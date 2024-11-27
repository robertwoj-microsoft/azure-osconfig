#ifndef BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_7_1_12_H
#define BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_7_1_12_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_1_12
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_1_12 benchmarks_cis_Ubuntu_24_04_v1_0_0_7_1_12_init();
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_7_1_12_audit(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_1_12* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_7_1_12_remediate(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_7_1_12* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_7_1_12_H

