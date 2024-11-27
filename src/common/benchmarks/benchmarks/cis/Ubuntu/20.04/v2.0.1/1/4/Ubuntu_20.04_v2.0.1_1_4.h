#ifndef BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_1_4_H
#define BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_1_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_20.04_v2.0.1_1_4_1.h"
#include "2/Ubuntu_20.04_v2.0.1_1_4_2.h"
#include "3/Ubuntu_20.04_v2.0.1_1_4_3.h"

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4
{
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4_1 rule_1;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4_2 rule_2;
    struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4_3 rule_3;
};

struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4 benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4_init();
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4_audit(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4_remediate(const struct benchmarks_cis_Ubuntu_20_04_v2_0_1_1_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_20_04_V2_0_1_1_4_H

