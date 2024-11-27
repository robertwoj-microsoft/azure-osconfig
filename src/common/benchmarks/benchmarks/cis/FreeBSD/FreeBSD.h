#ifndef BENCHMARKS_CIS_FREEBSD_H
#define BENCHMARKS_CIS_FREEBSD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "14/FreeBSD_14.h"

struct benchmarks_cis_FreeBSD
{
    struct benchmarks_cis_FreeBSD_14 rule_14;
};

struct benchmarks_cis_FreeBSD benchmarks_cis_FreeBSD_init();
benchmark_result_t benchmarks_cis_FreeBSD_audit(const struct benchmarks_cis_FreeBSD* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_FreeBSD_remediate(const struct benchmarks_cis_FreeBSD* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_FREEBSD_H

