#ifndef BENCHMARKS_CIS_SUSE_15_V1_1_1_3_2_H
#define BENCHMARKS_CIS_SUSE_15_V1_1_1_3_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_15_v1.1.1_3_2_1.h"
#include "2/SUSE_15_v1.1.1_3_2_2.h"

struct benchmarks_cis_SUSE_15_v1_1_1_3_2
{
    struct benchmarks_cis_SUSE_15_v1_1_1_3_2_1 rule_1;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_2_2 rule_2;
};

struct benchmarks_cis_SUSE_15_v1_1_1_3_2 benchmarks_cis_SUSE_15_v1_1_1_3_2_init();
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_3_2_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_3_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_3_2_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_3_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_15_V1_1_1_3_2_H

