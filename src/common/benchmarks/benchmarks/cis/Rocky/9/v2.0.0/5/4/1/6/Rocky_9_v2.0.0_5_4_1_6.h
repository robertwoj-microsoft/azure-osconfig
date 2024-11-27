#ifndef BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_4_1_6_H
#define BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_4_1_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Rocky_9_v2_0_0_5_4_1_6
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Rocky_9_v2_0_0_5_4_1_6 benchmarks_cis_Rocky_9_v2_0_0_5_4_1_6_init();
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_5_4_1_6_audit(const struct benchmarks_cis_Rocky_9_v2_0_0_5_4_1_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_5_4_1_6_remediate(const struct benchmarks_cis_Rocky_9_v2_0_0_5_4_1_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_4_1_6_H

