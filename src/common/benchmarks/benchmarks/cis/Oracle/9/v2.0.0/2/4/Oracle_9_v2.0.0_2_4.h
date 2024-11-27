#ifndef BENCHMARKS_CIS_ORACLE_9_V2_0_0_2_4_H
#define BENCHMARKS_CIS_ORACLE_9_V2_0_0_2_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Oracle_9_v2.0.0_2_4_1.h"
#include "2/Oracle_9_v2.0.0_2_4_2.h"

struct benchmarks_cis_Oracle_9_v2_0_0_2_4
{
    struct benchmarks_cis_Oracle_9_v2_0_0_2_4_1 rule_1;
    struct benchmarks_cis_Oracle_9_v2_0_0_2_4_2 rule_2;
};

struct benchmarks_cis_Oracle_9_v2_0_0_2_4 benchmarks_cis_Oracle_9_v2_0_0_2_4_init();
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_2_4_audit(const struct benchmarks_cis_Oracle_9_v2_0_0_2_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_2_4_remediate(const struct benchmarks_cis_Oracle_9_v2_0_0_2_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_9_V2_0_0_2_4_H

