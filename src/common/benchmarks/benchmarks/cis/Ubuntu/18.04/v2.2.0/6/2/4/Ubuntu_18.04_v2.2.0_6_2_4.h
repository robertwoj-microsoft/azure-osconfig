#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_6_2_4_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_6_2_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_6_2_4
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_6_2_4 benchmarks_cis_Ubuntu_18_04_v2_2_0_6_2_4_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_6_2_4_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_6_2_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_6_2_4_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_6_2_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_6_2_4_H

