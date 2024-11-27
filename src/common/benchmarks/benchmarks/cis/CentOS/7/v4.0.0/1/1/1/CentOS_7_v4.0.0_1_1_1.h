#ifndef BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_1_1_H
#define BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_1_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/CentOS_7_v4.0.0_1_1_1_1.h"
#include "2/CentOS_7_v4.0.0_1_1_1_2.h"
#include "3/CentOS_7_v4.0.0_1_1_1_3.h"
#include "4/CentOS_7_v4.0.0_1_1_1_4.h"
#include "5/CentOS_7_v4.0.0_1_1_1_5.h"
#include "8/CentOS_7_v4.0.0_1_1_1_8.h"

struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1
{
    struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_1 rule_1;
    struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2 rule_2;
    struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_3 rule_3;
    struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_4 rule_4;
    struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_5 rule_5;
    struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_8 rule_8;
};

struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1 benchmarks_cis_CentOS_7_v4_0_0_1_1_1_init();
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_1_1_1_audit(const struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_1_1_1_remediate(const struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_1_1_H

