#ifndef BENCHMARKS_CIS_SUSE_15_V1_1_1_1_1_H
#define BENCHMARKS_CIS_SUSE_15_V1_1_1_1_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/SUSE_15_v1.1.1_1_1_1.h"
#include "12/SUSE_15_v1.1.1_1_1_12.h"
#include "13/SUSE_15_v1.1.1_1_1_13.h"
#include "14/SUSE_15_v1.1.1_1_1_14.h"
#include "18/SUSE_15_v1.1.1_1_1_18.h"
#include "19/SUSE_15_v1.1.1_1_1_19.h"
#include "2/SUSE_15_v1.1.1_1_1_2.h"
#include "20/SUSE_15_v1.1.1_1_1_20.h"
#include "21/SUSE_15_v1.1.1_1_1_21.h"
#include "22/SUSE_15_v1.1.1_1_1_22.h"
#include "23/SUSE_15_v1.1.1_1_1_23.h"
#include "3/SUSE_15_v1.1.1_1_1_3.h"
#include "4/SUSE_15_v1.1.1_1_1_4.h"
#include "5/SUSE_15_v1.1.1_1_1_5.h"
#include "6/SUSE_15_v1.1.1_1_1_6.h"
#include "7/SUSE_15_v1.1.1_1_1_7.h"
#include "8/SUSE_15_v1.1.1_1_1_8.h"
#include "9/SUSE_15_v1.1.1_1_1_9.h"

struct benchmarks_cis_SUSE_15_v1_1_1_1_1
{
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_1 rule_1;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_12 rule_12;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_13 rule_13;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_14 rule_14;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_18 rule_18;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_19 rule_19;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_2 rule_2;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_20 rule_20;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_21 rule_21;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_22 rule_22;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_23 rule_23;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_3 rule_3;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_4 rule_4;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_5 rule_5;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_6 rule_6;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_7 rule_7;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_8 rule_8;
    struct benchmarks_cis_SUSE_15_v1_1_1_1_1_9 rule_9;
};

struct benchmarks_cis_SUSE_15_v1_1_1_1_1 benchmarks_cis_SUSE_15_v1_1_1_1_1_init();
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_1_1_audit(const struct benchmarks_cis_SUSE_15_v1_1_1_1_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_15_v1_1_1_1_1_remediate(const struct benchmarks_cis_SUSE_15_v1_1_1_1_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_15_V1_1_1_1_1_H

