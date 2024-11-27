#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_3_3_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_3_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_CentOS_8_v2_0_0_3_3_3
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_CentOS_8_v2_0_0_3_3_3 benchmarks_cis_CentOS_8_v2_0_0_3_3_3_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_3_3_3_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_3_3_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_3_3_3_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_3_3_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_3_3_3_H

