#ifndef BENCHMARKS_CIS_ORACLE_9_V2_0_0_7_1_H
#define BENCHMARKS_CIS_ORACLE_9_V2_0_0_7_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Oracle_9_v2.0.0_7_1_1.h"
#include "10/Oracle_9_v2.0.0_7_1_10.h"
#include "11/Oracle_9_v2.0.0_7_1_11.h"
#include "12/Oracle_9_v2.0.0_7_1_12.h"
#include "13/Oracle_9_v2.0.0_7_1_13.h"
#include "2/Oracle_9_v2.0.0_7_1_2.h"
#include "3/Oracle_9_v2.0.0_7_1_3.h"
#include "4/Oracle_9_v2.0.0_7_1_4.h"
#include "5/Oracle_9_v2.0.0_7_1_5.h"
#include "6/Oracle_9_v2.0.0_7_1_6.h"
#include "7/Oracle_9_v2.0.0_7_1_7.h"
#include "8/Oracle_9_v2.0.0_7_1_8.h"
#include "9/Oracle_9_v2.0.0_7_1_9.h"

struct benchmarks_cis_Oracle_9_v2_0_0_7_1
{
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_1 rule_1;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_10 rule_10;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_11 rule_11;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_12 rule_12;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_13 rule_13;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_2 rule_2;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_3 rule_3;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_4 rule_4;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_5 rule_5;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_6 rule_6;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_7 rule_7;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_8 rule_8;
    struct benchmarks_cis_Oracle_9_v2_0_0_7_1_9 rule_9;
};

struct benchmarks_cis_Oracle_9_v2_0_0_7_1 benchmarks_cis_Oracle_9_v2_0_0_7_1_init();
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_7_1_audit(const struct benchmarks_cis_Oracle_9_v2_0_0_7_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_9_v2_0_0_7_1_remediate(const struct benchmarks_cis_Oracle_9_v2_0_0_7_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_9_V2_0_0_7_1_H

