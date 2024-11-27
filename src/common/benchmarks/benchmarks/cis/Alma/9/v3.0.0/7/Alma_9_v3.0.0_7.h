#ifndef BENCHMARKS_CIS_ALMA_9_V3_0_0_7_H
#define BENCHMARKS_CIS_ALMA_9_V3_0_0_7_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../benchmarks_common.h"

#include "1/Alma_9_v3.0.0_7_1.h"
#include "2/Alma_9_v3.0.0_7_2.h"

struct benchmarks_cis_Alma_9_v3_0_0_7
{
    struct benchmarks_cis_Alma_9_v3_0_0_7_1 rule_1;
    struct benchmarks_cis_Alma_9_v3_0_0_7_2 rule_2;
};

struct benchmarks_cis_Alma_9_v3_0_0_7 benchmarks_cis_Alma_9_v3_0_0_7_init();
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_7_audit(const struct benchmarks_cis_Alma_9_v3_0_0_7* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_7_remediate(const struct benchmarks_cis_Alma_9_v3_0_0_7* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_9_V3_0_0_7_H

