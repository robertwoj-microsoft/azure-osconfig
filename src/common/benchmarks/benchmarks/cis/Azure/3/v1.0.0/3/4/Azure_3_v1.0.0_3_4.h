#ifndef BENCHMARKS_CIS_AZURE_3_V1_0_0_3_4_H
#define BENCHMARKS_CIS_AZURE_3_V1_0_0_3_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "3/Azure_3_v1.0.0_3_4_3.h"

struct benchmarks_cis_Azure_3_v1_0_0_3_4
{
    struct benchmarks_cis_Azure_3_v1_0_0_3_4_3 rule_3;
};

struct benchmarks_cis_Azure_3_v1_0_0_3_4 benchmarks_cis_Azure_3_v1_0_0_3_4_init();
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_3_4_audit(const struct benchmarks_cis_Azure_3_v1_0_0_3_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Azure_3_v1_0_0_3_4_remediate(const struct benchmarks_cis_Azure_3_v1_0_0_3_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_AZURE_3_V1_0_0_3_4_H

