#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_1_8_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_1_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_12_v3.1.0_1_8_1.h"

struct benchmarks_cis_SUSE_12_v3_1_0_1_8
{
    struct benchmarks_cis_SUSE_12_v3_1_0_1_8_1 rule_1;
};

struct benchmarks_cis_SUSE_12_v3_1_0_1_8 benchmarks_cis_SUSE_12_v3_1_0_1_8_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_1_8_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_1_8* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_1_8_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_1_8* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_1_8_H

