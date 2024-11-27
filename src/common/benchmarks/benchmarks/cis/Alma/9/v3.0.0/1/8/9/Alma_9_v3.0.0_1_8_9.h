#ifndef BENCHMARKS_CIS_ALMA_9_V3_0_0_1_8_9_H
#define BENCHMARKS_CIS_ALMA_9_V3_0_0_1_8_9_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Alma_9_v3_0_0_1_8_9
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Alma_9_v3_0_0_1_8_9 benchmarks_cis_Alma_9_v3_0_0_1_8_9_init();
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_8_9_audit(const struct benchmarks_cis_Alma_9_v3_0_0_1_8_9* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_8_9_remediate(const struct benchmarks_cis_Alma_9_v3_0_0_1_8_9* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_9_V3_0_0_1_8_9_H

