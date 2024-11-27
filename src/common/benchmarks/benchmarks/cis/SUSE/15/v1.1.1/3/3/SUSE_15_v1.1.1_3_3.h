#ifndef BENCHMARKS_CIS_SUSE_15_V1_1_1_3_3_H
#define BENCHMARKS_CIS_SUSE_15_V1_1_1_3_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_15_v1.1.1_3_3_1.h"
#include "2/SUSE_15_v1.1.1_3_3_2.h"
#include "3/SUSE_15_v1.1.1_3_3_3.h"
#include "4/SUSE_15_v1.1.1_3_3_4.h"
#include "5/SUSE_15_v1.1.1_3_3_5.h"
#include "6/SUSE_15_v1.1.1_3_3_6.h"
#include "7/SUSE_15_v1.1.1_3_3_7.h"
#include "8/SUSE_15_v1.1.1_3_3_8.h"
#include "9/SUSE_15_v1.1.1_3_3_9.h"

struct benchmarks_cis_SUSE_15_v1_1_1_3_3
{
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_1 rule_1;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_2 rule_2;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_3 rule_3;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_4 rule_4;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_5 rule_5;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_6 rule_6;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_7 rule_7;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_8 rule_8;
    struct benchmarks_cis_SUSE_15_v1_1_1_3_3_9 rule_9;
};

struct benchmarks_cis_SUSE_15_v1_1_1_3_3 benchmarks_cis_SUSE_15_v1_1_1_3_3_init();
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_3_3_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_3_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_3_3_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_3_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_15_V1_1_1_3_3_H

