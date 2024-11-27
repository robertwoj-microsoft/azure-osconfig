#ifndef BENCHMARKS_CIS_SUSE_15_V1_1_1_5_5_H
#define BENCHMARKS_CIS_SUSE_15_V1_1_1_5_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

struct benchmarks_cis_SUSE_15_v1_1_1_5_5
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_SUSE_15_v1_1_1_5_5 benchmarks_cis_SUSE_15_v1_1_1_5_5_init();
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_5_5_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_5_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_5_5_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_5_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_15_V1_1_1_5_5_H

