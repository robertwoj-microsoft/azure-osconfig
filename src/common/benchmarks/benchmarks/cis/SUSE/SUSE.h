#ifndef BENCHMARKS_CIS_SUSE_H
#define BENCHMARKS_CIS_SUSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "12/SUSE_12.h"
#include "15/SUSE_15.h"

struct benchmarks_cis_SUSE
{
    struct benchmarks_cis_SUSE_12 rule_12;
    struct benchmarks_cis_SUSE_15 rule_15;
};

struct benchmarks_cis_SUSE benchmarks_cis_SUSE_init();
benchmark_result_t benchmarks_cis_SUSE_audit(const struct benchmarks_cis_SUSE* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_remediate(const struct benchmarks_cis_SUSE* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_H

