#ifndef BENCHMARKS_CIS_ALMA_9_V3_0_0_1_2_2_H
#define BENCHMARKS_CIS_ALMA_9_V3_0_0_1_2_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/Alma_9_v3.0.0_1_2_2_1.h"

struct benchmarks_cis_Alma_9_v3_0_0_1_2_2
{
    struct benchmarks_cis_Alma_9_v3_0_0_1_2_2_1 rule_1;
};

struct benchmarks_cis_Alma_9_v3_0_0_1_2_2 benchmarks_cis_Alma_9_v3_0_0_1_2_2_init();
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_2_2_audit(const struct benchmarks_cis_Alma_9_v3_0_0_1_2_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_2_2_remediate(const struct benchmarks_cis_Alma_9_v3_0_0_1_2_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_9_V3_0_0_1_2_2_H

