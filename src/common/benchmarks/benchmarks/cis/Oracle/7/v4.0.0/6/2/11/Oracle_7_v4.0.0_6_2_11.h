#ifndef BENCHMARKS_CIS_ORACLE_7_V4_0_0_6_2_11_H
#define BENCHMARKS_CIS_ORACLE_7_V4_0_0_6_2_11_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Oracle_7_v4_0_0_6_2_11
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Oracle_7_v4_0_0_6_2_11 benchmarks_cis_Oracle_7_v4_0_0_6_2_11_init();
benchmark_result_t benchmarks_cis_Oracle_7_v4_0_0_6_2_11_audit(const struct benchmarks_cis_Oracle_7_v4_0_0_6_2_11* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_7_v4_0_0_6_2_11_remediate(const struct benchmarks_cis_Oracle_7_v4_0_0_6_2_11* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_7_V4_0_0_6_2_11_H

