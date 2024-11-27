#ifndef BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_2_22_H
#define BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_2_22_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Rocky_8_v2_0_0_2_2_22
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Rocky_8_v2_0_0_2_2_22 benchmarks_cis_Rocky_8_v2_0_0_2_2_22_init();
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_2_2_22_audit(const struct benchmarks_cis_Rocky_8_v2_0_0_2_2_22* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_2_2_22_remediate(const struct benchmarks_cis_Rocky_8_v2_0_0_2_2_22* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_2_22_H

