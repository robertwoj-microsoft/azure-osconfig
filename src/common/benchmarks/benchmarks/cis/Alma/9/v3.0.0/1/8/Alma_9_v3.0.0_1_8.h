#ifndef BENCHMARKS_CIS_ALMA_9_V3_0_0_1_8_H
#define BENCHMARKS_CIS_ALMA_9_V3_0_0_1_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "10/Alma_9_v3.0.0_1_8_10.h"
#include "2/Alma_9_v3.0.0_1_8_2.h"
#include "3/Alma_9_v3.0.0_1_8_3.h"
#include "4/Alma_9_v3.0.0_1_8_4.h"
#include "5/Alma_9_v3.0.0_1_8_5.h"
#include "6/Alma_9_v3.0.0_1_8_6.h"
#include "7/Alma_9_v3.0.0_1_8_7.h"
#include "8/Alma_9_v3.0.0_1_8_8.h"
#include "9/Alma_9_v3.0.0_1_8_9.h"

struct benchmarks_cis_Alma_9_v3_0_0_1_8
{
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_10 rule_10;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_2 rule_2;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_3 rule_3;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_4 rule_4;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_5 rule_5;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_6 rule_6;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_7 rule_7;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_8 rule_8;
    struct benchmarks_cis_Alma_9_v3_0_0_1_8_9 rule_9;
};

struct benchmarks_cis_Alma_9_v3_0_0_1_8 benchmarks_cis_Alma_9_v3_0_0_1_8_init();
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_8_audit(const struct benchmarks_cis_Alma_9_v3_0_0_1_8* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_8_remediate(const struct benchmarks_cis_Alma_9_v3_0_0_1_8* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_9_V3_0_0_1_8_H

