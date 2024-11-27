#ifndef BENCHMARKS_CIS_ORACLE_8_V3_0_0_1_5_H
#define BENCHMARKS_CIS_ORACLE_8_V3_0_0_1_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Oracle_8_v3.0.0_1_5_1.h"

struct benchmarks_cis_Oracle_8_v3_0_0_1_5
{
    struct benchmarks_cis_Oracle_8_v3_0_0_1_5_1 rule_1;
};

struct benchmarks_cis_Oracle_8_v3_0_0_1_5 benchmarks_cis_Oracle_8_v3_0_0_1_5_init();
benchmark_result_t benchmarks_cis_Oracle_8_v3_0_0_1_5_audit(const struct benchmarks_cis_Oracle_8_v3_0_0_1_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_8_v3_0_0_1_5_remediate(const struct benchmarks_cis_Oracle_8_v3_0_0_1_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_8_V3_0_0_1_5_H

