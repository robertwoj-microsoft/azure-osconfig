#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_2_3_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_2_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_12_v3.1.0_2_3_1.h"
#include "2/SUSE_12_v3.1.0_2_3_2.h"
#include "3/SUSE_12_v3.1.0_2_3_3.h"
#include "4/SUSE_12_v3.1.0_2_3_4.h"
#include "5/SUSE_12_v3.1.0_2_3_5.h"

struct benchmarks_cis_SUSE_12_v3_1_0_2_3
{
    struct benchmarks_cis_SUSE_12_v3_1_0_2_3_1 rule_1;
    struct benchmarks_cis_SUSE_12_v3_1_0_2_3_2 rule_2;
    struct benchmarks_cis_SUSE_12_v3_1_0_2_3_3 rule_3;
    struct benchmarks_cis_SUSE_12_v3_1_0_2_3_4 rule_4;
    struct benchmarks_cis_SUSE_12_v3_1_0_2_3_5 rule_5;
};

struct benchmarks_cis_SUSE_12_v3_1_0_2_3 benchmarks_cis_SUSE_12_v3_1_0_2_3_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_3_audit(const struct benchmarks_cis_SUSE_12_v3_1_0_2_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_2_3_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0_2_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_2_3_H

