#ifndef BENCHMARKS_CIS_FREEBSD_14_V1_0_0_2_H
#define BENCHMARKS_CIS_FREEBSD_14_V1_0_0_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../benchmarks_common.h"

#include "1/FreeBSD_14_v1.0.0_2_1.h"
#include "2/FreeBSD_14_v1.0.0_2_2.h"

struct benchmarks_cis_FreeBSD_14_v1_0_0_2
{
    struct benchmarks_cis_FreeBSD_14_v1_0_0_2_1 rule_1;
    struct benchmarks_cis_FreeBSD_14_v1_0_0_2_2 rule_2;
};

struct benchmarks_cis_FreeBSD_14_v1_0_0_2 benchmarks_cis_FreeBSD_14_v1_0_0_2_init();
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_2_audit(const struct benchmarks_cis_FreeBSD_14_v1_0_0_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_2_remediate(const struct benchmarks_cis_FreeBSD_14_v1_0_0_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_FREEBSD_14_V1_0_0_2_H

