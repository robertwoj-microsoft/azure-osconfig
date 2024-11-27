#ifndef BENCHMARKS_CIS_DEBIAN_12_V1_1_0_3_3_11_H
#define BENCHMARKS_CIS_DEBIAN_12_V1_1_0_3_3_11_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Debian_12_v1_1_0_3_3_11
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Debian_12_v1_1_0_3_3_11 benchmarks_cis_Debian_12_v1_1_0_3_3_11_init();
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_3_3_11_audit(const struct benchmarks_cis_Debian_12_v1_1_0_3_3_11* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_3_3_11_remediate(const struct benchmarks_cis_Debian_12_v1_1_0_3_3_11* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_V1_1_0_3_3_11_H

