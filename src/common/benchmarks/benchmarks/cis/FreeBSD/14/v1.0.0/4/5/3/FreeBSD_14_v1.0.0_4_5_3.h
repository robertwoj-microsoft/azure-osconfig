#ifndef BENCHMARKS_CIS_FREEBSD_14_V1_0_0_4_5_3_H
#define BENCHMARKS_CIS_FREEBSD_14_V1_0_0_4_5_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "2/FreeBSD_14_v1.0.0_4_5_3_2.h"

struct benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3
{
    struct benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3_2 rule_2;
};

struct benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3 benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3_init();
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3_audit(const struct benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3_remediate(const struct benchmarks_cis_FreeBSD_14_v1_0_0_4_5_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_FREEBSD_14_V1_0_0_4_5_3_H

