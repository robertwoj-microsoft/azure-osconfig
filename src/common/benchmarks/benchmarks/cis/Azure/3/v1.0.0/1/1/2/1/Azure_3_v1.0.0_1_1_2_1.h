#ifndef BENCHMARKS_CIS_AZURE_3_V1_0_0_1_1_2_1_H
#define BENCHMARKS_CIS_AZURE_3_V1_0_0_1_1_2_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Azure_3_v1_0_0_1_1_2_1
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Azure_3_v1_0_0_1_1_2_1 benchmarks_cis_Azure_3_v1_0_0_1_1_2_1_init();
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_1_1_2_1_audit(const struct benchmarks_cis_Azure_3_v1_0_0_1_1_2_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_1_1_2_1_remediate(const struct benchmarks_cis_Azure_3_v1_0_0_1_1_2_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_AZURE_3_V1_0_0_1_1_2_1_H

