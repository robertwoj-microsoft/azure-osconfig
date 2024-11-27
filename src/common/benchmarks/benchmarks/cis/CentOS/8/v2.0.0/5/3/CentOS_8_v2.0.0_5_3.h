#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_5_3_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_5_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/CentOS_8_v2.0.0_5_3_1.h"
#include "2/CentOS_8_v2.0.0_5_3_2.h"
#include "3/CentOS_8_v2.0.0_5_3_3.h"
#include "5/CentOS_8_v2.0.0_5_3_5.h"
#include "6/CentOS_8_v2.0.0_5_3_6.h"
#include "7/CentOS_8_v2.0.0_5_3_7.h"

struct benchmarks_cis_CentOS_8_v2_0_0_5_3
{
    struct benchmarks_cis_CentOS_8_v2_0_0_5_3_1 rule_1;
    struct benchmarks_cis_CentOS_8_v2_0_0_5_3_2 rule_2;
    struct benchmarks_cis_CentOS_8_v2_0_0_5_3_3 rule_3;
    struct benchmarks_cis_CentOS_8_v2_0_0_5_3_5 rule_5;
    struct benchmarks_cis_CentOS_8_v2_0_0_5_3_6 rule_6;
    struct benchmarks_cis_CentOS_8_v2_0_0_5_3_7 rule_7;
};

struct benchmarks_cis_CentOS_8_v2_0_0_5_3 benchmarks_cis_CentOS_8_v2_0_0_5_3_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_5_3_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_5_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_5_3_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_5_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_5_3_H

