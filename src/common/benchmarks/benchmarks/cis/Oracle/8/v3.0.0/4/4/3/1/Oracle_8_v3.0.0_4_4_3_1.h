#ifndef BENCHMARKS_CIS_ORACLE_8_V3_0_0_4_4_3_1_H
#define BENCHMARKS_CIS_ORACLE_8_V3_0_0_4_4_3_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "1/Oracle_8_v3.0.0_4_4_3_1_1.h"
#include "2/Oracle_8_v3.0.0_4_4_3_1_2.h"

struct benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1
{
    struct benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1_1 rule_1;
    struct benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1_2 rule_2;
};

struct benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1 benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1_init();
benchmark_result_t benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1_audit(const struct benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1_remediate(const struct benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_8_V3_0_0_4_4_3_1_H

