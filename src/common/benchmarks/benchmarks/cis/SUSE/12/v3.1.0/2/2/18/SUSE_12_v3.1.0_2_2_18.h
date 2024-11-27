#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_2_2_18_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_2_2_18_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_SUSE_12_v3_1_0_2_2_18
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_SUSE_12_v3_1_0_2_2_18 benchmarks_cis_SUSE_12_v3_1_0_2_2_18_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_2_18_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_2_2_18* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_2_18_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_2_2_18* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_2_2_18_H

