#ifndef BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_4_4_H
#define BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_4_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Ubuntu_18.04_v2.2.0_4_4_1.h"
#include "2/Ubuntu_18.04_v2.2.0_4_4_2.h"
#include "3/Ubuntu_18.04_v2.2.0_4_4_3.h"
#include "4/Ubuntu_18.04_v2.2.0_4_4_4.h"
#include "5/Ubuntu_18.04_v2.2.0_4_4_5.h"

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4
{
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_1 rule_1;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_2 rule_2;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_3 rule_3;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_4 rule_4;
    struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_5 rule_5;
};

struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4 benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_init();
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_audit(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4_remediate(const struct benchmarks_cis_Ubuntu_18_04_v2_2_0_4_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_18_04_V2_2_0_4_4_H

