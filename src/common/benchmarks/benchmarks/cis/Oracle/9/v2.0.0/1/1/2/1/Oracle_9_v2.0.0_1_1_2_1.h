#ifndef BENCHMARKS_CIS_ORACLE_9_V2_0_0_1_1_2_1_H
#define BENCHMARKS_CIS_ORACLE_9_V2_0_0_1_1_2_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "1/Oracle_9_v2.0.0_1_1_2_1_1.h"
#include "2/Oracle_9_v2.0.0_1_1_2_1_2.h"
#include "3/Oracle_9_v2.0.0_1_1_2_1_3.h"
#include "4/Oracle_9_v2.0.0_1_1_2_1_4.h"

struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1
{
    struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1_1 rule_1;
    struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1_2 rule_2;
    struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1_3 rule_3;
    struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1_4 rule_4;
};

struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1 benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1_init();
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1_audit(const struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1_remediate(const struct benchmarks_cis_Oracle_9_v2_0_0_1_1_2_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_9_V2_0_0_1_1_2_1_H

