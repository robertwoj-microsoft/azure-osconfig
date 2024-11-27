#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_4_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/CentOS_8_v2.0.0_3_4_1.h"
#include "2/CentOS_8_v2.0.0_3_4_2.h"
#include "3/CentOS_8_v2.0.0_3_4_3.h"

struct benchmarks_cis_CentOS_8_v2_0_0_3_4
{
    struct benchmarks_cis_CentOS_8_v2_0_0_3_4_1 rule_1;
    struct benchmarks_cis_CentOS_8_v2_0_0_3_4_2 rule_2;
    struct benchmarks_cis_CentOS_8_v2_0_0_3_4_3 rule_3;
};

struct benchmarks_cis_CentOS_8_v2_0_0_3_4 benchmarks_cis_CentOS_8_v2_0_0_3_4_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_3_4_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_3_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_3_4_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_3_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_4_H

