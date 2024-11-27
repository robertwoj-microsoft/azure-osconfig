#ifndef BENCHMARKS_CIS_DEBIAN_11_V2_0_0_6_2_H
#define BENCHMARKS_CIS_DEBIAN_11_V2_0_0_6_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Debian_11_v2.0.0_6_2_1.h"
#include "2/Debian_11_v2.0.0_6_2_2.h"

struct benchmarks_cis_Debian_11_v2_0_0_6_2
{
    struct benchmarks_cis_Debian_11_v2_0_0_6_2_1 rule_1;
    struct benchmarks_cis_Debian_11_v2_0_0_6_2_2 rule_2;
};

struct benchmarks_cis_Debian_11_v2_0_0_6_2 benchmarks_cis_Debian_11_v2_0_0_6_2_init();
benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_6_2_audit(const struct benchmarks_cis_Debian_11_v2_0_0_6_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_11_v2_0_0_6_2_remediate(const struct benchmarks_cis_Debian_11_v2_0_0_6_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_11_V2_0_0_6_2_H

