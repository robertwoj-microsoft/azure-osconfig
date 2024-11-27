#ifndef BENCHMARKS_CIS_ALMA_H
#define BENCHMARKS_CIS_ALMA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "8/Alma_8.h"
#include "9/Alma_9.h"

struct benchmarks_cis_Alma
{
    struct benchmarks_cis_Alma_8 rule_8;
    struct benchmarks_cis_Alma_9 rule_9;
};

struct benchmarks_cis_Alma benchmarks_cis_Alma_init();
benchmark_result_t benchmarks_cis_Alma_audit(const struct benchmarks_cis_Alma* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_remediate(const struct benchmarks_cis_Alma* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_H

