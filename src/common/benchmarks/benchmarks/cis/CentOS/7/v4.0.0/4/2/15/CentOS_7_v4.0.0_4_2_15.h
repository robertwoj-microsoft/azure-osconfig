#ifndef BENCHMARKS_CIS_CENTOS_7_V4_0_0_4_2_15_H
#define BENCHMARKS_CIS_CENTOS_7_V4_0_0_4_2_15_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_CentOS_7_v4_0_0_4_2_15
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_CentOS_7_v4_0_0_4_2_15 benchmarks_cis_CentOS_7_v4_0_0_4_2_15_init();
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_4_2_15_audit(const struct benchmarks_cis_CentOS_7_v4_0_0_4_2_15* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_7_v4_0_0_4_2_15_remediate(const struct benchmarks_cis_CentOS_7_v4_0_0_4_2_15* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_7_V4_0_0_4_2_15_H

