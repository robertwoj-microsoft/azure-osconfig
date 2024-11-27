#ifndef BENCHMARKS_CIS_DEBIAN_12_V1_1_0_5_4_3_H
#define BENCHMARKS_CIS_DEBIAN_12_V1_1_0_5_4_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "2/Debian_12_v1.1.0_5_4_3_2.h"
#include "3/Debian_12_v1.1.0_5_4_3_3.h"

struct benchmarks_cis_Debian_12_v1_1_0_5_4_3
{
    struct benchmarks_cis_Debian_12_v1_1_0_5_4_3_2 rule_2;
    struct benchmarks_cis_Debian_12_v1_1_0_5_4_3_3 rule_3;
};

struct benchmarks_cis_Debian_12_v1_1_0_5_4_3 benchmarks_cis_Debian_12_v1_1_0_5_4_3_init();
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_5_4_3_audit(const struct benchmarks_cis_Debian_12_v1_1_0_5_4_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_5_4_3_remediate(const struct benchmarks_cis_Debian_12_v1_1_0_5_4_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_V1_1_0_5_4_3_H

