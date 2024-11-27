#ifndef BENCHMARKS_CIS_DEBIAN_12_V1_1_0_6_H
#define BENCHMARKS_CIS_DEBIAN_12_V1_1_0_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../benchmarks_common.h"

#include "1/Debian_12_v1.1.0_6_1.h"
#include "3/Debian_12_v1.1.0_6_3.h"

struct benchmarks_cis_Debian_12_v1_1_0_6
{
    struct benchmarks_cis_Debian_12_v1_1_0_6_1 rule_1;
    struct benchmarks_cis_Debian_12_v1_1_0_6_3 rule_3;
};

struct benchmarks_cis_Debian_12_v1_1_0_6 benchmarks_cis_Debian_12_v1_1_0_6_init();
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_6_audit(const struct benchmarks_cis_Debian_12_v1_1_0_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_6_remediate(const struct benchmarks_cis_Debian_12_v1_1_0_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_V1_1_0_6_H

