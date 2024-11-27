#ifndef BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_2_21_H
#define BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_2_21_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Rocky_8_v2_0_0_2_2_21
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Rocky_8_v2_0_0_2_2_21 benchmarks_cis_Rocky_8_v2_0_0_2_2_21_init();
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_2_2_21_audit(const struct benchmarks_cis_Rocky_8_v2_0_0_2_2_21* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_2_2_21_remediate(const struct benchmarks_cis_Rocky_8_v2_0_0_2_2_21* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_2_21_H

