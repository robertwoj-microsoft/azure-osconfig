#ifndef BENCHMARKS_CIS_CENTOS_7_V4_0_0_3_3_H
#define BENCHMARKS_CIS_CENTOS_7_V4_0_0_3_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/CentOS_7_v4.0.0_3_3_1.h"
#include "10/CentOS_7_v4.0.0_3_3_10.h"
#include "11/CentOS_7_v4.0.0_3_3_11.h"
#include "2/CentOS_7_v4.0.0_3_3_2.h"
#include "3/CentOS_7_v4.0.0_3_3_3.h"
#include "4/CentOS_7_v4.0.0_3_3_4.h"
#include "5/CentOS_7_v4.0.0_3_3_5.h"
#include "6/CentOS_7_v4.0.0_3_3_6.h"
#include "7/CentOS_7_v4.0.0_3_3_7.h"
#include "8/CentOS_7_v4.0.0_3_3_8.h"
#include "9/CentOS_7_v4.0.0_3_3_9.h"

struct benchmarks_cis_CentOS_7_v4_0_0_3_3
{
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_1 rule_1;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_10 rule_10;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_11 rule_11;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_2 rule_2;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_3 rule_3;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_4 rule_4;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_5 rule_5;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_6 rule_6;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_7 rule_7;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_8 rule_8;
    struct benchmarks_cis_CentOS_7_v4_0_0_3_3_9 rule_9;
};

struct benchmarks_cis_CentOS_7_v4_0_0_3_3 benchmarks_cis_CentOS_7_v4_0_0_3_3_init();
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_3_3_audit(const struct benchmarks_cis_CentOS_7_v4_0_0_3_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_3_3_remediate(const struct benchmarks_cis_CentOS_7_v4_0_0_3_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_7_V4_0_0_3_3_H

