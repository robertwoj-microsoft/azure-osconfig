#ifndef BENCHMARKS_CIS_ALMA_9_V3_0_0_1_7_H
#define BENCHMARKS_CIS_ALMA_9_V3_0_0_1_7_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Alma_9_v3.0.0_1_7_1.h"
#include "2/Alma_9_v3.0.0_1_7_2.h"
#include "3/Alma_9_v3.0.0_1_7_3.h"
#include "4/Alma_9_v3.0.0_1_7_4.h"
#include "5/Alma_9_v3.0.0_1_7_5.h"
#include "6/Alma_9_v3.0.0_1_7_6.h"

struct benchmarks_cis_Alma_9_v3_0_0_1_7
{
    struct benchmarks_cis_Alma_9_v3_0_0_1_7_1 rule_1;
    struct benchmarks_cis_Alma_9_v3_0_0_1_7_2 rule_2;
    struct benchmarks_cis_Alma_9_v3_0_0_1_7_3 rule_3;
    struct benchmarks_cis_Alma_9_v3_0_0_1_7_4 rule_4;
    struct benchmarks_cis_Alma_9_v3_0_0_1_7_5 rule_5;
    struct benchmarks_cis_Alma_9_v3_0_0_1_7_6 rule_6;
};

struct benchmarks_cis_Alma_9_v3_0_0_1_7 benchmarks_cis_Alma_9_v3_0_0_1_7_init();
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_7_audit(const struct benchmarks_cis_Alma_9_v3_0_0_1_7* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Alma_9_v3_0_0_1_7_remediate(const struct benchmarks_cis_Alma_9_v3_0_0_1_7* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ALMA_9_V3_0_0_1_7_H

