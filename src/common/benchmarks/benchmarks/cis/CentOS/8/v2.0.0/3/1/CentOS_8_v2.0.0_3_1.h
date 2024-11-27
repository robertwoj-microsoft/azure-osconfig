#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_1_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/CentOS_8_v2.0.0_3_1_1.h"
#include "4/CentOS_8_v2.0.0_3_1_4.h"

struct benchmarks_cis_CentOS_8_v2_0_0_3_1
{
    struct benchmarks_cis_CentOS_8_v2_0_0_3_1_1 rule_1;
    struct benchmarks_cis_CentOS_8_v2_0_0_3_1_4 rule_4;
};

struct benchmarks_cis_CentOS_8_v2_0_0_3_1 benchmarks_cis_CentOS_8_v2_0_0_3_1_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_3_1_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_3_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_3_1_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_3_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_1_H

