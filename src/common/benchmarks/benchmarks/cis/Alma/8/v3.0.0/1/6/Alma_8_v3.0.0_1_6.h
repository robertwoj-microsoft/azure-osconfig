#ifndef BENCHMARKS_CIS_ALMA_8_V3_0_0_1_6_H
#define BENCHMARKS_CIS_ALMA_8_V3_0_0_1_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Alma_8_v3.0.0_1_6_1.h"
#include "2/Alma_8_v3.0.0_1_6_2.h"
#include "3/Alma_8_v3.0.0_1_6_3.h"
#include "4/Alma_8_v3.0.0_1_6_4.h"

struct benchmarks_cis_Alma_8_v3_0_0_1_6
{
    struct benchmarks_cis_Alma_8_v3_0_0_1_6_1 rule_1;
    struct benchmarks_cis_Alma_8_v3_0_0_1_6_2 rule_2;
    struct benchmarks_cis_Alma_8_v3_0_0_1_6_3 rule_3;
    struct benchmarks_cis_Alma_8_v3_0_0_1_6_4 rule_4;
};

struct benchmarks_cis_Alma_8_v3_0_0_1_6 benchmarks_cis_Alma_8_v3_0_0_1_6_init();
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_1_6_audit(const struct benchmarks_cis_Alma_8_v3_0_0_1_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_1_6_remediate(const struct benchmarks_cis_Alma_8_v3_0_0_1_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_8_V3_0_0_1_6_H

