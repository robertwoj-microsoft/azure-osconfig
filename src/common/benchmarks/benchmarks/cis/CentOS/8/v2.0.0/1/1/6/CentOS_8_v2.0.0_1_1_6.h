#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_1_1_6_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_1_1_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "2/CentOS_8_v2.0.0_1_1_6_2.h"
#include "3/CentOS_8_v2.0.0_1_1_6_3.h"
#include "4/CentOS_8_v2.0.0_1_1_6_4.h"

struct benchmarks_cis_CentOS_8_v2_0_0_1_1_6
{
    struct benchmarks_cis_CentOS_8_v2_0_0_1_1_6_2 rule_2;
    struct benchmarks_cis_CentOS_8_v2_0_0_1_1_6_3 rule_3;
    struct benchmarks_cis_CentOS_8_v2_0_0_1_1_6_4 rule_4;
};

struct benchmarks_cis_CentOS_8_v2_0_0_1_1_6 benchmarks_cis_CentOS_8_v2_0_0_1_1_6_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_1_1_6_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_1_1_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_1_1_6_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_1_1_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_1_1_6_H

