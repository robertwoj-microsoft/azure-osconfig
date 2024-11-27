#ifndef BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_3_2_H
#define BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_3_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "1/Debian_10_v2.0.0_3_4_3_2_1.h"
#include "2/Debian_10_v2.0.0_3_4_3_2_2.h"
#include "3/Debian_10_v2.0.0_3_4_3_2_3.h"
#include "4/Debian_10_v2.0.0_3_4_3_2_4.h"

struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2
{
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2_1 rule_1;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2_2 rule_2;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2_3 rule_3;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2_4 rule_4;
};

struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2 benchmarks_cis_Debian_10_v2_0_0_3_4_3_2_init();
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_3_4_3_2_audit(const struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_3_4_3_2_remediate(const struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_3_2_H

