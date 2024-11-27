#ifndef BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_3_3_H
#define BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_3_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "1/Debian_10_v2.0.0_3_4_3_3_1.h"
#include "2/Debian_10_v2.0.0_3_4_3_3_2.h"
#include "3/Debian_10_v2.0.0_3_4_3_3_3.h"
#include "4/Debian_10_v2.0.0_3_4_3_3_4.h"

struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3
{
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3_1 rule_1;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3_2 rule_2;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3_3 rule_3;
    struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3_4 rule_4;
};

struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3 benchmarks_cis_Debian_10_v2_0_0_3_4_3_3_init();
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_3_4_3_3_audit(const struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_10_v2_0_0_3_4_3_3_remediate(const struct benchmarks_cis_Debian_10_v2_0_0_3_4_3_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_10_V2_0_0_3_4_3_3_H

