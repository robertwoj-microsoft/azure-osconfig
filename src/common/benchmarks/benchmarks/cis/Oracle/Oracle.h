#ifndef BENCHMARKS_CIS_ORACLE_H
#define BENCHMARKS_CIS_ORACLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "7/Oracle_7.h"
#include "8/Oracle_8.h"
#include "9/Oracle_9.h"

struct benchmarks_cis_Oracle
{
    struct benchmarks_cis_Oracle_7 rule_7;
    struct benchmarks_cis_Oracle_8 rule_8;
    struct benchmarks_cis_Oracle_9 rule_9;
};

struct benchmarks_cis_Oracle benchmarks_cis_Oracle_init();
benchmark_result_t benchmarks_cis_Oracle_audit(const struct benchmarks_cis_Oracle* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Oracle_remediate(const struct benchmarks_cis_Oracle* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ORACLE_H

