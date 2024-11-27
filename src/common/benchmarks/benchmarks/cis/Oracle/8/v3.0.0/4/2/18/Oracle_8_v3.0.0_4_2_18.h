#ifndef BENCHMARKS_CIS_ORACLE_8_V3_0_0_4_2_18_H
#define BENCHMARKS_CIS_ORACLE_8_V3_0_0_4_2_18_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Oracle_8_v3_0_0_4_2_18
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Oracle_8_v3_0_0_4_2_18 benchmarks_cis_Oracle_8_v3_0_0_4_2_18_init();
benchmark_result_t benchmarks_cis_Oracle_8_v3_0_0_4_2_18_audit(const struct benchmarks_cis_Oracle_8_v3_0_0_4_2_18* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_8_v3_0_0_4_2_18_remediate(const struct benchmarks_cis_Oracle_8_v3_0_0_4_2_18* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_8_V3_0_0_4_2_18_H

