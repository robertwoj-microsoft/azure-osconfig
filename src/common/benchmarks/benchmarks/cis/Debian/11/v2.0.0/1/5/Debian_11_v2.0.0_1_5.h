#ifndef BENCHMARKS_CIS_DEBIAN_11_V2_0_0_1_5_H
#define BENCHMARKS_CIS_DEBIAN_11_V2_0_0_1_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Debian_11_v2.0.0_1_5_1.h"
#include "2/Debian_11_v2.0.0_1_5_2.h"
#include "3/Debian_11_v2.0.0_1_5_3.h"
#include "4/Debian_11_v2.0.0_1_5_4.h"
#include "5/Debian_11_v2.0.0_1_5_5.h"

struct benchmarks_cis_Debian_11_v2_0_0_1_5
{
    struct benchmarks_cis_Debian_11_v2_0_0_1_5_1 rule_1;
    struct benchmarks_cis_Debian_11_v2_0_0_1_5_2 rule_2;
    struct benchmarks_cis_Debian_11_v2_0_0_1_5_3 rule_3;
    struct benchmarks_cis_Debian_11_v2_0_0_1_5_4 rule_4;
    struct benchmarks_cis_Debian_11_v2_0_0_1_5_5 rule_5;
};

struct benchmarks_cis_Debian_11_v2_0_0_1_5 benchmarks_cis_Debian_11_v2_0_0_1_5_init();
benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_1_5_audit(const struct benchmarks_cis_Debian_11_v2_0_0_1_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_1_5_remediate(const struct benchmarks_cis_Debian_11_v2_0_0_1_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_11_V2_0_0_1_5_H

