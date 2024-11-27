#ifndef BENCHMARKS_CIS_AZURE_3_V1_0_0_3_3_9_H
#define BENCHMARKS_CIS_AZURE_3_V1_0_0_3_3_9_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Azure_3_v1_0_0_3_3_9
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Azure_3_v1_0_0_3_3_9 benchmarks_cis_Azure_3_v1_0_0_3_3_9_init();
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_3_3_9_audit(const struct benchmarks_cis_Azure_3_v1_0_0_3_3_9* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_3_3_9_remediate(const struct benchmarks_cis_Azure_3_v1_0_0_3_3_9* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_AZURE_3_V1_0_0_3_3_9_H

