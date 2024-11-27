#ifndef BENCHMARKS_CIS_FREEBSD_14_V1_0_0_1_1_2_6_H
#define BENCHMARKS_CIS_FREEBSD_14_V1_0_0_1_1_2_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "2/FreeBSD_14_v1.0.0_1_1_2_6_2.h"
#include "3/FreeBSD_14_v1.0.0_1_1_2_6_3.h"

struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6
{
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6_2 rule_2;
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6_3 rule_3;
};

struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6 benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6_init();
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6_audit(const struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6_remediate(const struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1_2_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_FREEBSD_14_V1_0_0_1_1_2_6_H

