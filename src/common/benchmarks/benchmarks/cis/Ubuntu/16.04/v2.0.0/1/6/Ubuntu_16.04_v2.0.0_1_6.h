#ifndef BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_1_6_H
#define BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_1_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_16.04_v2.0.0_1_6_1.h"

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6
{
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6_1 rule_1;
};

struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6 benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6_init();
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6_audit(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6_remediate(const struct benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_16_04_V2_0_0_1_6_H

