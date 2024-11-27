#ifndef BENCHMARKS_CIS_ALMA_8_V3_0_0_3_4_H
#define BENCHMARKS_CIS_ALMA_8_V3_0_0_3_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Alma_8_v3.0.0_3_4_1.h"
#include "2/Alma_8_v3.0.0_3_4_2.h"

struct benchmarks_cis_Alma_8_v3_0_0_3_4
{
    struct benchmarks_cis_Alma_8_v3_0_0_3_4_1 rule_1;
    struct benchmarks_cis_Alma_8_v3_0_0_3_4_2 rule_2;
};

struct benchmarks_cis_Alma_8_v3_0_0_3_4 benchmarks_cis_Alma_8_v3_0_0_3_4_init();
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_3_4_audit(const struct benchmarks_cis_Alma_8_v3_0_0_3_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_3_4_remediate(const struct benchmarks_cis_Alma_8_v3_0_0_3_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_8_V3_0_0_3_4_H

