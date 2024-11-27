#ifndef BENCHMARKS_CIS_SUSE_15_V1_1_1_4_2_H
#define BENCHMARKS_CIS_SUSE_15_V1_1_1_4_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_15_v1.1.1_4_2_1.h"
#include "2/SUSE_15_v1.1.1_4_2_2.h"
#include "3/SUSE_15_v1.1.1_4_2_3.h"
#include "4/SUSE_15_v1.1.1_4_2_4.h"

struct benchmarks_cis_SUSE_15_v1_1_1_4_2
{
    struct benchmarks_cis_SUSE_15_v1_1_1_4_2_1 rule_1;
    struct benchmarks_cis_SUSE_15_v1_1_1_4_2_2 rule_2;
    struct benchmarks_cis_SUSE_15_v1_1_1_4_2_3 rule_3;
    struct benchmarks_cis_SUSE_15_v1_1_1_4_2_4 rule_4;
};

struct benchmarks_cis_SUSE_15_v1_1_1_4_2 benchmarks_cis_SUSE_15_v1_1_1_4_2_init();
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_4_2_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_4_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_4_2_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_4_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_15_V1_1_1_4_2_H

