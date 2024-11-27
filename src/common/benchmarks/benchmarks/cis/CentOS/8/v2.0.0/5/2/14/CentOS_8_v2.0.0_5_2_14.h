#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_5_2_14_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_5_2_14_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_CentOS_8_v2_0_0_5_2_14
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_CentOS_8_v2_0_0_5_2_14 benchmarks_cis_CentOS_8_v2_0_0_5_2_14_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_5_2_14_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_5_2_14* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_5_2_14_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_5_2_14* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_5_2_14_H

