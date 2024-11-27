#ifndef BENCHMARKS_CIS_CENTOS_7_V4_0_0_2_2_H
#define BENCHMARKS_CIS_CENTOS_7_V4_0_0_2_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/CentOS_7_v4.0.0_2_2_1.h"
#include "10/CentOS_7_v4.0.0_2_2_10.h"
#include "11/CentOS_7_v4.0.0_2_2_11.h"
#include "12/CentOS_7_v4.0.0_2_2_12.h"
#include "13/CentOS_7_v4.0.0_2_2_13.h"
#include "14/CentOS_7_v4.0.0_2_2_14.h"
#include "15/CentOS_7_v4.0.0_2_2_15.h"
#include "16/CentOS_7_v4.0.0_2_2_16.h"
#include "17/CentOS_7_v4.0.0_2_2_17.h"
#include "18/CentOS_7_v4.0.0_2_2_18.h"
#include "19/CentOS_7_v4.0.0_2_2_19.h"
#include "2/CentOS_7_v4.0.0_2_2_2.h"
#include "21/CentOS_7_v4.0.0_2_2_21.h"
#include "22/CentOS_7_v4.0.0_2_2_22.h"
#include "3/CentOS_7_v4.0.0_2_2_3.h"
#include "4/CentOS_7_v4.0.0_2_2_4.h"
#include "5/CentOS_7_v4.0.0_2_2_5.h"
#include "6/CentOS_7_v4.0.0_2_2_6.h"
#include "7/CentOS_7_v4.0.0_2_2_7.h"
#include "8/CentOS_7_v4.0.0_2_2_8.h"
#include "9/CentOS_7_v4.0.0_2_2_9.h"

struct benchmarks_cis_CentOS_7_v4_0_0_2_2
{
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_1 rule_1;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_10 rule_10;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_11 rule_11;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_12 rule_12;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_13 rule_13;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_14 rule_14;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_15 rule_15;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_16 rule_16;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_17 rule_17;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_18 rule_18;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_19 rule_19;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_2 rule_2;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_21 rule_21;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_22 rule_22;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_3 rule_3;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_4 rule_4;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_5 rule_5;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_6 rule_6;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_7 rule_7;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_8 rule_8;
    struct benchmarks_cis_CentOS_7_v4_0_0_2_2_9 rule_9;
};

struct benchmarks_cis_CentOS_7_v4_0_0_2_2 benchmarks_cis_CentOS_7_v4_0_0_2_2_init();
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_2_2_audit(const struct benchmarks_cis_CentOS_7_v4_0_0_2_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_2_2_remediate(const struct benchmarks_cis_CentOS_7_v4_0_0_2_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_7_V4_0_0_2_2_H

