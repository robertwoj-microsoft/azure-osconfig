#ifndef BENCHMARKS_CIS_DEBIAN_12_V1_1_0_1_5_H
#define BENCHMARKS_CIS_DEBIAN_12_V1_1_0_1_5_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Debian_12_v1.1.0_1_5_1.h"
#include "2/Debian_12_v1.1.0_1_5_2.h"
#include "3/Debian_12_v1.1.0_1_5_3.h"

struct benchmarks_cis_Debian_12_v1_1_0_1_5
{
    struct benchmarks_cis_Debian_12_v1_1_0_1_5_1 rule_1;
    struct benchmarks_cis_Debian_12_v1_1_0_1_5_2 rule_2;
    struct benchmarks_cis_Debian_12_v1_1_0_1_5_3 rule_3;
};

struct benchmarks_cis_Debian_12_v1_1_0_1_5 benchmarks_cis_Debian_12_v1_1_0_1_5_init();
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_1_5_audit(const struct benchmarks_cis_Debian_12_v1_1_0_1_5* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_v1_1_0_1_5_remediate(const struct benchmarks_cis_Debian_12_v1_1_0_1_5* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_V1_1_0_1_5_H

