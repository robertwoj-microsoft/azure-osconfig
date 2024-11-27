#ifndef BENCHMARKS_CIS_DEBIAN_10_V2_0_0_2_2_15_H
#define BENCHMARKS_CIS_DEBIAN_10_V2_0_0_2_2_15_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Debian_10_v2_0_0_2_2_15
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Debian_10_v2_0_0_2_2_15 benchmarks_cis_Debian_10_v2_0_0_2_2_15_init();
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_2_2_15_audit(const struct benchmarks_cis_Debian_10_v2_0_0_2_2_15* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_2_2_15_remediate(const struct benchmarks_cis_Debian_10_v2_0_0_2_2_15* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_10_V2_0_0_2_2_15_H

