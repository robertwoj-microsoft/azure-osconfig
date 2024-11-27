#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_3_5_1_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_3_5_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/SUSE_12_v3.1.0_3_5_1_1.h"

struct benchmarks_cis_SUSE_12_v3_1_0_3_5_1
{
    struct benchmarks_cis_SUSE_12_v3_1_0_3_5_1_1 rule_1;
};

struct benchmarks_cis_SUSE_12_v3_1_0_3_5_1 benchmarks_cis_SUSE_12_v3_1_0_3_5_1_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_3_5_1_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_3_5_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_3_5_1_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_3_5_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_3_5_1_H

