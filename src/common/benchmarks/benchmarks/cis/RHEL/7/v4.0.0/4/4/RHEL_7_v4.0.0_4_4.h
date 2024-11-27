#ifndef BENCHMARKS_CIS_RHEL_7_V4_0_0_4_4_H
#define BENCHMARKS_CIS_RHEL_7_V4_0_0_4_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/RHEL_7_v4.0.0_4_4_1.h"
#include "2/RHEL_7_v4.0.0_4_4_2.h"

struct benchmarks_cis_RHEL_7_v4_0_0_4_4
{
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_1 rule_1;
    struct benchmarks_cis_RHEL_7_v4_0_0_4_4_2 rule_2;
};

struct benchmarks_cis_RHEL_7_v4_0_0_4_4 benchmarks_cis_RHEL_7_v4_0_0_4_4_init();
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_4_4_audit(const struct benchmarks_cis_RHEL_7_v4_0_0_4_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_RHEL_7_v4_0_0_4_4_remediate(const struct benchmarks_cis_RHEL_7_v4_0_0_4_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_RHEL_7_V4_0_0_4_4_H

