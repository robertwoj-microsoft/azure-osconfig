#ifndef BENCHMARKS_CIS_AZURE_H
#define BENCHMARKS_CIS_AZURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "3/Azure_3.h"

struct benchmarks_cis_Azure
{
    struct benchmarks_cis_Azure_3 rule_3;
};

struct benchmarks_cis_Azure benchmarks_cis_Azure_init();
benchmark_result_t benchmarks_cis_Azure_audit(const struct benchmarks_cis_Azure* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Azure_remediate(const struct benchmarks_cis_Azure* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_AZURE_H

