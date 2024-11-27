#ifndef BENCHMARKS_CIS_ALMA_9_H
#define BENCHMARKS_CIS_ALMA_9_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v3.0.0/Alma_9_v3.0.0.h"

struct benchmarks_cis_Alma_9
{
    struct benchmarks_cis_Alma_9_v3_0_0 rule_v3_0_0;
};

struct benchmarks_cis_Alma_9 benchmarks_cis_Alma_9_init();
benchmark_result_t benchmarks_cis_Alma_9_audit(const struct benchmarks_cis_Alma_9* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_9_remediate(const struct benchmarks_cis_Alma_9* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_9_H

