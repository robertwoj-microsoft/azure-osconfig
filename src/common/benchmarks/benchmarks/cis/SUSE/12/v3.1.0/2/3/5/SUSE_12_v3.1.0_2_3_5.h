#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_2_3_5_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_2_3_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_SUSE_12_v3_1_0_2_3_5
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_SUSE_12_v3_1_0_2_3_5 benchmarks_cis_SUSE_12_v3_1_0_2_3_5_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_3_5_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_2_3_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_3_5_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_2_3_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_2_3_5_H

