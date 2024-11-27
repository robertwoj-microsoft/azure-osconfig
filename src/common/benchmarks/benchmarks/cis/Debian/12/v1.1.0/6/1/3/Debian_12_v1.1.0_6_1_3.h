#ifndef BENCHMARKS_CIS_DEBIAN_12_V1_1_0_6_1_3_H
#define BENCHMARKS_CIS_DEBIAN_12_V1_1_0_6_1_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/Debian_12_v1.1.0_6_1_3_1.h"
#include "2/Debian_12_v1.1.0_6_1_3_2.h"
#include "3/Debian_12_v1.1.0_6_1_3_3.h"
#include "4/Debian_12_v1.1.0_6_1_3_4.h"
#include "5/Debian_12_v1.1.0_6_1_3_5.h"
#include "6/Debian_12_v1.1.0_6_1_3_6.h"
#include "7/Debian_12_v1.1.0_6_1_3_7.h"
#include "8/Debian_12_v1.1.0_6_1_3_8.h"

struct benchmarks_cis_Debian_12_v1_1_0_6_1_3
{
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_1 rule_1;
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_2 rule_2;
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_3 rule_3;
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_4 rule_4;
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_5 rule_5;
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_6 rule_6;
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_7 rule_7;
    struct benchmarks_cis_Debian_12_v1_1_0_6_1_3_8 rule_8;
};

struct benchmarks_cis_Debian_12_v1_1_0_6_1_3 benchmarks_cis_Debian_12_v1_1_0_6_1_3_init();
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_6_1_3_audit(const struct benchmarks_cis_Debian_12_v1_1_0_6_1_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_6_1_3_remediate(const struct benchmarks_cis_Debian_12_v1_1_0_6_1_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_V1_1_0_6_1_3_H

