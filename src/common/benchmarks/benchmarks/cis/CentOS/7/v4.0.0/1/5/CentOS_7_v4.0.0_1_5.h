#ifndef BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_5_H
#define BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/CentOS_7_v4.0.0_1_5_1.h"

struct benchmarks_cis_CentOS_7_v4_0_0_1_5
{
    struct benchmarks_cis_CentOS_7_v4_0_0_1_5_1 rule_1;
};

struct benchmarks_cis_CentOS_7_v4_0_0_1_5 benchmarks_cis_CentOS_7_v4_0_0_1_5_init();
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_1_5_audit(const struct benchmarks_cis_CentOS_7_v4_0_0_1_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_1_5_remediate(const struct benchmarks_cis_CentOS_7_v4_0_0_1_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_5_H

