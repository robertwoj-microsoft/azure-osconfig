#ifndef BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_6_1_4_H
#define BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_6_1_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/Ubuntu_24.04_v1.0.0_6_1_4_1.h"

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4
{
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_1 rule_1;
};

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4 benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_init();
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_audit(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_remediate(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_6_1_4_H

