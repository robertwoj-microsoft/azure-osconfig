#ifndef BENCHMARKS_CIS_ORACLE_7_V4_0_0_H
#define BENCHMARKS_CIS_ORACLE_7_V4_0_0_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../benchmarks_common.h"

#include "1/Oracle_7_v4.0.0_1.h"
#include "2/Oracle_7_v4.0.0_2.h"
#include "3/Oracle_7_v4.0.0_3.h"
#include "4/Oracle_7_v4.0.0_4.h"
#include "5/Oracle_7_v4.0.0_5.h"
#include "6/Oracle_7_v4.0.0_6.h"

struct benchmarks_cis_Oracle_7_v4_0_0
{
    struct benchmarks_cis_Oracle_7_v4_0_0_1 rule_1;
    struct benchmarks_cis_Oracle_7_v4_0_0_2 rule_2;
    struct benchmarks_cis_Oracle_7_v4_0_0_3 rule_3;
    struct benchmarks_cis_Oracle_7_v4_0_0_4 rule_4;
    struct benchmarks_cis_Oracle_7_v4_0_0_5 rule_5;
    struct benchmarks_cis_Oracle_7_v4_0_0_6 rule_6;
};

struct benchmarks_cis_Oracle_7_v4_0_0 benchmarks_cis_Oracle_7_v4_0_0_init();
benchmark_result_t benchmarks_cis_Oracle_7_v4_0_0_audit(const struct benchmarks_cis_Oracle_7_v4_0_0* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_7_v4_0_0_remediate(const struct benchmarks_cis_Oracle_7_v4_0_0* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_7_V4_0_0_H

