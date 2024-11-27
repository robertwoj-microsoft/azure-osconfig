#ifndef BENCHMARKS_CIS_SUSE_15_V1_1_1_1_7_H
#define BENCHMARKS_CIS_SUSE_15_V1_1_1_1_7_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_15_v1.1.1_1_7_1.h"

struct benchmarks_cis_SUSE_15_v1_1_1_1_7
{
    struct benchmarks_cis_SUSE_15_v1_1_1_1_7_1 rule_1;
};

struct benchmarks_cis_SUSE_15_v1_1_1_1_7 benchmarks_cis_SUSE_15_v1_1_1_1_7_init();
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_1_7_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_1_7* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_1_7_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_1_7* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_15_V1_1_1_1_7_H

