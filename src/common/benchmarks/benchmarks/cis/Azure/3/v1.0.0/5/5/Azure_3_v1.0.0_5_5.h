#ifndef BENCHMARKS_CIS_AZURE_3_V1_0_0_5_5_H
#define BENCHMARKS_CIS_AZURE_3_V1_0_0_5_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Azure_3_v1.0.0_5_5_1.h"
#include "2/Azure_3_v1.0.0_5_5_2.h"
#include "3/Azure_3_v1.0.0_5_5_3.h"
#include "4/Azure_3_v1.0.0_5_5_4.h"

struct benchmarks_cis_Azure_3_v1_0_0_5_5
{
    struct benchmarks_cis_Azure_3_v1_0_0_5_5_1 rule_1;
    struct benchmarks_cis_Azure_3_v1_0_0_5_5_2 rule_2;
    struct benchmarks_cis_Azure_3_v1_0_0_5_5_3 rule_3;
    struct benchmarks_cis_Azure_3_v1_0_0_5_5_4 rule_4;
};

struct benchmarks_cis_Azure_3_v1_0_0_5_5 benchmarks_cis_Azure_3_v1_0_0_5_5_init();
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_5_5_audit(const struct benchmarks_cis_Azure_3_v1_0_0_5_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_5_5_remediate(const struct benchmarks_cis_Azure_3_v1_0_0_5_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_AZURE_3_V1_0_0_5_5_H

