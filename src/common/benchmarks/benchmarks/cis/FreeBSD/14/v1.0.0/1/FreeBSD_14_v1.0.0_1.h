#ifndef BENCHMARKS_CIS_FREEBSD_14_V1_0_0_1_H
#define BENCHMARKS_CIS_FREEBSD_14_V1_0_0_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../benchmarks_common.h"

#include "1/FreeBSD_14_v1.0.0_1_1.h"
#include "2/FreeBSD_14_v1.0.0_1_2.h"
#include "3/FreeBSD_14_v1.0.0_1_3.h"
#include "4/FreeBSD_14_v1.0.0_1_4.h"
#include "6/FreeBSD_14_v1.0.0_1_6.h"

struct benchmarks_cis_FreeBSD_14_v1_0_0_1
{
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_1 rule_1;
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_2 rule_2;
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_3 rule_3;
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_4 rule_4;
    struct benchmarks_cis_FreeBSD_14_v1_0_0_1_6 rule_6;
};

struct benchmarks_cis_FreeBSD_14_v1_0_0_1 benchmarks_cis_FreeBSD_14_v1_0_0_1_init();
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_1_audit(const struct benchmarks_cis_FreeBSD_14_v1_0_0_1* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_FreeBSD_14_v1_0_0_1_remediate(const struct benchmarks_cis_FreeBSD_14_v1_0_0_1* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_FREEBSD_14_V1_0_0_1_H

