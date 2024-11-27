#ifndef BENCHMARKS_CIS_ORACLE_7_V4_0_0_4_5_H
#define BENCHMARKS_CIS_ORACLE_7_V4_0_0_4_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Oracle_7_v4.0.0_4_5_1.h"
#include "2/Oracle_7_v4.0.0_4_5_2.h"
#include "3/Oracle_7_v4.0.0_4_5_3.h"

struct benchmarks_cis_Oracle_7_v4_0_0_4_5
{
    struct benchmarks_cis_Oracle_7_v4_0_0_4_5_1 rule_1;
    struct benchmarks_cis_Oracle_7_v4_0_0_4_5_2 rule_2;
    struct benchmarks_cis_Oracle_7_v4_0_0_4_5_3 rule_3;
};

struct benchmarks_cis_Oracle_7_v4_0_0_4_5 benchmarks_cis_Oracle_7_v4_0_0_4_5_init();
benchmark_result_t benchmarks_cis_Oracle_7_v4_0_0_4_5_audit(const struct benchmarks_cis_Oracle_7_v4_0_0_4_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_7_v4_0_0_4_5_remediate(const struct benchmarks_cis_Oracle_7_v4_0_0_4_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_7_V4_0_0_4_5_H

