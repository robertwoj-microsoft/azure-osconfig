#ifndef BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_1_H
#define BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/Debian_10_v2.0.0_3_4_1_1.h"
#include "2/Debian_10_v2.0.0_3_4_1_2.h"
#include "3/Debian_10_v2.0.0_3_4_1_3.h"
#include "4/Debian_10_v2.0.0_3_4_1_4.h"
#include "5/Debian_10_v2.0.0_3_4_1_5.h"
#include "6/Debian_10_v2.0.0_3_4_1_6.h"
#include "7/Debian_10_v2.0.0_3_4_1_7.h"

struct benchmarks_cis_Debian_10_v2_0_0_3_4_1
{
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_1_1 rule_1;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_1_2 rule_2;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_1_3 rule_3;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_1_4 rule_4;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_1_5 rule_5;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_1_6 rule_6;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_1_7 rule_7;
};

struct benchmarks_cis_Debian_10_v2_0_0_3_4_1 benchmarks_cis_Debian_10_v2_0_0_3_4_1_init();
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_3_4_1_audit(const struct benchmarks_cis_Debian_10_v2_0_0_3_4_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_3_4_1_remediate(const struct benchmarks_cis_Debian_10_v2_0_0_3_4_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_1_H

