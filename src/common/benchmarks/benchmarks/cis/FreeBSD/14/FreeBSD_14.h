#ifndef BENCHMARKS_CIS_FREEBSD_14_H
#define BENCHMARKS_CIS_FREEBSD_14_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v1.0.0/FreeBSD_14_v1.0.0.h"

struct benchmarks_cis_FreeBSD_14
{
    struct benchmarks_cis_FreeBSD_14_v1_0_0 rule_v1_0_0;
};

struct benchmarks_cis_FreeBSD_14 benchmarks_cis_FreeBSD_14_init();
benchmark_result_t benchmarks_cis_FreeBSD_14_audit(const struct benchmarks_cis_FreeBSD_14* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_FreeBSD_14_remediate(const struct benchmarks_cis_FreeBSD_14* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_FREEBSD_14_H

