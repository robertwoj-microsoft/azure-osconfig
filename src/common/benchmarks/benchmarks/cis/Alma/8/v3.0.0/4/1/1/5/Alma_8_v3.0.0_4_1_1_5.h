#ifndef BENCHMARKS_CIS_ALMA_8_V3_0_0_4_1_1_5_H
#define BENCHMARKS_CIS_ALMA_8_V3_0_0_4_1_1_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_5
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_5 benchmarks_cis_Alma_8_v3_0_0_4_1_1_5_init();
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_4_1_1_5_audit(const struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_4_1_1_5_remediate(const struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_8_V3_0_0_4_1_1_5_H

