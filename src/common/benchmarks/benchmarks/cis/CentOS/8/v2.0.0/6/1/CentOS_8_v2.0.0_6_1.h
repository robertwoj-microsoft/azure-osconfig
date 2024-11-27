#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_6_1_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_6_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "10/CentOS_8_v2.0.0_6_1_10.h"
#include "11/CentOS_8_v2.0.0_6_1_11.h"
#include "12/CentOS_8_v2.0.0_6_1_12.h"
#include "13/CentOS_8_v2.0.0_6_1_13.h"
#include "14/CentOS_8_v2.0.0_6_1_14.h"
#include "15/CentOS_8_v2.0.0_6_1_15.h"
#include "2/CentOS_8_v2.0.0_6_1_2.h"
#include "3/CentOS_8_v2.0.0_6_1_3.h"
#include "4/CentOS_8_v2.0.0_6_1_4.h"
#include "5/CentOS_8_v2.0.0_6_1_5.h"
#include "6/CentOS_8_v2.0.0_6_1_6.h"
#include "7/CentOS_8_v2.0.0_6_1_7.h"
#include "8/CentOS_8_v2.0.0_6_1_8.h"
#include "9/CentOS_8_v2.0.0_6_1_9.h"

struct benchmarks_cis_CentOS_8_v2_0_0_6_1
{
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_10 rule_10;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_11 rule_11;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_12 rule_12;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_13 rule_13;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_14 rule_14;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_15 rule_15;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_2 rule_2;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_3 rule_3;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_4 rule_4;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_5 rule_5;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_6 rule_6;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_7 rule_7;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_8 rule_8;
    struct benchmarks_cis_CentOS_8_v2_0_0_6_1_9 rule_9;
};

struct benchmarks_cis_CentOS_8_v2_0_0_6_1 benchmarks_cis_CentOS_8_v2_0_0_6_1_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_6_1_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_6_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_6_1_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_6_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_6_1_H

