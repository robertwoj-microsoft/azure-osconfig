#ifndef BENCHMARKS_CIS_DEBIAN_12_V1_1_0_5_2_H
#define BENCHMARKS_CIS_DEBIAN_12_V1_1_0_5_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Debian_12_v1.1.0_5_2_1.h"
#include "2/Debian_12_v1.1.0_5_2_2.h"
#include "3/Debian_12_v1.1.0_5_2_3.h"
#include "5/Debian_12_v1.1.0_5_2_5.h"
#include "6/Debian_12_v1.1.0_5_2_6.h"
#include "7/Debian_12_v1.1.0_5_2_7.h"

struct benchmarks_cis_Debian_12_v1_1_0_5_2
{
    struct benchmarks_cis_Debian_12_v1_1_0_5_2_1 rule_1;
    struct benchmarks_cis_Debian_12_v1_1_0_5_2_2 rule_2;
    struct benchmarks_cis_Debian_12_v1_1_0_5_2_3 rule_3;
    struct benchmarks_cis_Debian_12_v1_1_0_5_2_5 rule_5;
    struct benchmarks_cis_Debian_12_v1_1_0_5_2_6 rule_6;
    struct benchmarks_cis_Debian_12_v1_1_0_5_2_7 rule_7;
};

struct benchmarks_cis_Debian_12_v1_1_0_5_2 benchmarks_cis_Debian_12_v1_1_0_5_2_init();
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_5_2_audit(const struct benchmarks_cis_Debian_12_v1_1_0_5_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_5_2_remediate(const struct benchmarks_cis_Debian_12_v1_1_0_5_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_V1_1_0_5_2_H

