#ifndef BENCHMARKS_CIS_ORACLE_9_V2_0_0_7_1_10_H
#define BENCHMARKS_CIS_ORACLE_9_V2_0_0_7_1_10_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Oracle_9_v2_0_0_7_1_10
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Oracle_9_v2_0_0_7_1_10 benchmarks_cis_Oracle_9_v2_0_0_7_1_10_init();
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_7_1_10_audit(const struct benchmarks_cis_Oracle_9_v2_0_0_7_1_10* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_7_1_10_remediate(const struct benchmarks_cis_Oracle_9_v2_0_0_7_1_10* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_9_V2_0_0_7_1_10_H

