#ifndef BENCHMARKS_CIS_SUSE_12_V3_1_0_H
#define BENCHMARKS_CIS_SUSE_12_V3_1_0_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../benchmarks_common.h"

#include "1/SUSE_12_v3.1.0_1.h"
#include "2/SUSE_12_v3.1.0_2.h"
#include "3/SUSE_12_v3.1.0_3.h"
#include "4/SUSE_12_v3.1.0_4.h"
#include "5/SUSE_12_v3.1.0_5.h"
#include "6/SUSE_12_v3.1.0_6.h"

struct benchmarks_cis_SUSE_12_v3_1_0
{
    struct benchmarks_cis_SUSE_12_v3_1_0_1 rule_1;
    struct benchmarks_cis_SUSE_12_v3_1_0_2 rule_2;
    struct benchmarks_cis_SUSE_12_v3_1_0_3 rule_3;
    struct benchmarks_cis_SUSE_12_v3_1_0_4 rule_4;
    struct benchmarks_cis_SUSE_12_v3_1_0_5 rule_5;
    struct benchmarks_cis_SUSE_12_v3_1_0_6 rule_6;
};

struct benchmarks_cis_SUSE_12_v3_1_0 benchmarks_cis_SUSE_12_v3_1_0_init();
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_audit(const struct benchmarks_cis_SUSE_12_v3_1_0* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_v3_1_0_remediate(const struct benchmarks_cis_SUSE_12_v3_1_0* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_V3_1_0_H

