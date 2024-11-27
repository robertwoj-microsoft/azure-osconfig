#ifndef BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_1_1_2_H
#define BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_1_1_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2 benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2_init();
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2_audit(const struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2_remediate(const struct benchmarks_cis_CentOS_7_v4_0_0_1_1_1_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_7_V4_0_0_1_1_1_2_H

