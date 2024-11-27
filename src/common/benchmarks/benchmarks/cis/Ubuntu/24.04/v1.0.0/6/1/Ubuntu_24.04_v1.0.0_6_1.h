#ifndef BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_6_1_H
#define BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_6_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_24.04_v1.0.0_6_1_1.h"
#include "2/Ubuntu_24.04_v1.0.0_6_1_2.h"
#include "3/Ubuntu_24.04_v1.0.0_6_1_3.h"
#include "4/Ubuntu_24.04_v1.0.0_6_1_4.h"

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1
{
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_1 rule_1;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_2 rule_2;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_3 rule_3;
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4 rule_4;
};

struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1 benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_init();
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_audit(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_remediate(const struct benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_24_04_V1_0_0_6_1_H

