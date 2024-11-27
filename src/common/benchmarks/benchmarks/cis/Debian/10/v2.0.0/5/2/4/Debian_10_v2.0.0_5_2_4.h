#ifndef BENCHMARKS_CIS_DEBIAN_10_V2_0_0_5_2_4_H
#define BENCHMARKS_CIS_DEBIAN_10_V2_0_0_5_2_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "11/Debian_10_v2.0.0_5_2_4_11.h"

struct benchmarks_cis_Debian_10_v2_0_0_5_2_4
{
    struct benchmarks_cis_Debian_10_v2_0_0_5_2_4_11 rule_11;
};

struct benchmarks_cis_Debian_10_v2_0_0_5_2_4 benchmarks_cis_Debian_10_v2_0_0_5_2_4_init();
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_5_2_4_audit(const struct benchmarks_cis_Debian_10_v2_0_0_5_2_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_5_2_4_remediate(const struct benchmarks_cis_Debian_10_v2_0_0_5_2_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_10_V2_0_0_5_2_4_H

