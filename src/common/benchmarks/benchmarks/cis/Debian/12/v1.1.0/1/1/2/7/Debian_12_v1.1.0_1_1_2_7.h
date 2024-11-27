#ifndef BENCHMARKS_CIS_DEBIAN_12_V1_1_0_1_1_2_7_H
#define BENCHMARKS_CIS_DEBIAN_12_V1_1_0_1_1_2_7_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "2/Debian_12_v1.1.0_1_1_2_7_2.h"
#include "3/Debian_12_v1.1.0_1_1_2_7_3.h"
#include "4/Debian_12_v1.1.0_1_1_2_7_4.h"

struct benchmarks_cis_Debian_12_v1_1_0_1_1_2_7
{
    struct benchmarks_cis_Debian_12_v1_1_0_1_1_2_7_2 rule_2;
    struct benchmarks_cis_Debian_12_v1_1_0_1_1_2_7_3 rule_3;
    struct benchmarks_cis_Debian_12_v1_1_0_1_1_2_7_4 rule_4;
};

struct benchmarks_cis_Debian_12_v1_1_0_1_1_2_7 benchmarks_cis_Debian_12_v1_1_0_1_1_2_7_init();
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_1_1_2_7_audit(const struct benchmarks_cis_Debian_12_v1_1_0_1_1_2_7* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_1_1_2_7_remediate(const struct benchmarks_cis_Debian_12_v1_1_0_1_1_2_7* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_V1_1_0_1_1_2_7_H

