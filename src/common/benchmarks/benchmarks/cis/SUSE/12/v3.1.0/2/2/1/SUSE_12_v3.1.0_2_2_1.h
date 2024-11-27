#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_2_2_1_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_2_2_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/SUSE_12_v3.1.0_2_2_1_1.h"
#include "2/SUSE_12_v3.1.0_2_2_1_2.h"
#include "3/SUSE_12_v3.1.0_2_2_1_3.h"
#include "4/SUSE_12_v3.1.0_2_2_1_4.h"

struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1
{
    struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1_1 rule_1;
    struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1_2 rule_2;
    struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1_3 rule_3;
    struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1_4 rule_4;
};

struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1 benchmarks_cis_SUSE_12_v3_1_0_2_2_1_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_2_1_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_2_1_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_2_2_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_2_2_1_H

