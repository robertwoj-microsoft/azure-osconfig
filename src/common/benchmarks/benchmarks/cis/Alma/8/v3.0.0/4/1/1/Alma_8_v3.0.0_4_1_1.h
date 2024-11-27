#ifndef BENCHMARKS_CIS_ALMA_8_V3_0_0_4_1_1_H
#define BENCHMARKS_CIS_ALMA_8_V3_0_0_4_1_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/Alma_8_v3.0.0_4_1_1_1.h"
#include "2/Alma_8_v3.0.0_4_1_1_2.h"
#include "3/Alma_8_v3.0.0_4_1_1_3.h"
#include "4/Alma_8_v3.0.0_4_1_1_4.h"
#include "5/Alma_8_v3.0.0_4_1_1_5.h"
#include "6/Alma_8_v3.0.0_4_1_1_6.h"
#include "7/Alma_8_v3.0.0_4_1_1_7.h"
#include "8/Alma_8_v3.0.0_4_1_1_8.h"

struct benchmarks_cis_Alma_8_v3_0_0_4_1_1
{
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_1 rule_1;
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_2 rule_2;
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_3 rule_3;
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_4 rule_4;
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_5 rule_5;
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_6 rule_6;
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_7 rule_7;
    struct benchmarks_cis_Alma_8_v3_0_0_4_1_1_8 rule_8;
};

struct benchmarks_cis_Alma_8_v3_0_0_4_1_1 benchmarks_cis_Alma_8_v3_0_0_4_1_1_init();
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_4_1_1_audit(const struct benchmarks_cis_Alma_8_v3_0_0_4_1_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_8_v3_0_0_4_1_1_remediate(const struct benchmarks_cis_Alma_8_v3_0_0_4_1_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_8_V3_0_0_4_1_1_H

