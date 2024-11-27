#ifndef BENCHMARKS_CIS_DEBIAN_11_V2_0_0_1_2_2_1_H
#define BENCHMARKS_CIS_DEBIAN_11_V2_0_0_1_2_2_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Debian_11_v2_0_0_1_2_2_1
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Debian_11_v2_0_0_1_2_2_1 benchmarks_cis_Debian_11_v2_0_0_1_2_2_1_init();
benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_1_2_2_1_audit(const struct benchmarks_cis_Debian_11_v2_0_0_1_2_2_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_1_2_2_1_remediate(const struct benchmarks_cis_Debian_11_v2_0_0_1_2_2_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_11_V2_0_0_1_2_2_1_H

