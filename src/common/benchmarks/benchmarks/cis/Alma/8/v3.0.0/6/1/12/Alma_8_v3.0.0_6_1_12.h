#ifndef BENCHMARKS_CIS_ALMA_8_V3_0_0_6_1_12_H
#define BENCHMARKS_CIS_ALMA_8_V3_0_0_6_1_12_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Alma_8_v3_0_0_6_1_12
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Alma_8_v3_0_0_6_1_12 benchmarks_cis_Alma_8_v3_0_0_6_1_12_init();
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_6_1_12_audit(const struct benchmarks_cis_Alma_8_v3_0_0_6_1_12* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_6_1_12_remediate(const struct benchmarks_cis_Alma_8_v3_0_0_6_1_12* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_8_V3_0_0_6_1_12_H

