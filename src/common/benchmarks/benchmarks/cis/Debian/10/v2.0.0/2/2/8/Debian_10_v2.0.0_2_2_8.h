#ifndef BENCHMARKS_CIS_DEBIAN_10_V2_0_0_2_2_8_H
#define BENCHMARKS_CIS_DEBIAN_10_V2_0_0_2_2_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

struct benchmarks_cis_Debian_10_v2_0_0_2_2_8
{
    bench_action_t audit;
    bench_action_t remediate;
};

struct benchmarks_cis_Debian_10_v2_0_0_2_2_8 benchmarks_cis_Debian_10_v2_0_0_2_2_8_init();
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_2_2_8_audit(const struct benchmarks_cis_Debian_10_v2_0_0_2_2_8* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_2_2_8_remediate(const struct benchmarks_cis_Debian_10_v2_0_0_2_2_8* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_10_V2_0_0_2_2_8_H

