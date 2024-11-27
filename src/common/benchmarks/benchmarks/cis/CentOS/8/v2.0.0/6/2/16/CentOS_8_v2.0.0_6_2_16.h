#ifndef BENCHMARKS_CIS_CENTOS_8_V2_0_0_6_2_16_H
#define BENCHMARKS_CIS_CENTOS_8_V2_0_0_6_2_16_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_CentOS_8_v2_0_0_6_2_16
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_CentOS_8_v2_0_0_6_2_16 benchmarks_cis_CentOS_8_v2_0_0_6_2_16_init();
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_6_2_16_audit(const struct benchmarks_cis_CentOS_8_v2_0_0_6_2_16* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_v2_0_0_6_2_16_remediate(const struct benchmarks_cis_CentOS_8_v2_0_0_6_2_16* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_V2_0_0_6_2_16_H

