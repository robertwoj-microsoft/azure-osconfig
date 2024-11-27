#ifndef BENCHMARKS_CIS_SUSE_15_H
#define BENCHMARKS_CIS_SUSE_15_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v1.1.1/SUSE_15_v1.1.1.h"

struct benchmarks_cis_SUSE_15
{
    struct benchmarks_cis_SUSE_15_v1_1_1 rule_v1_1_1;
};

struct benchmarks_cis_SUSE_15 benchmarks_cis_SUSE_15_init();
benchmark_result_t benchmarks_cis_SUSE_15_audit(const struct benchmarks_cis_SUSE_15* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_15_remediate(const struct benchmarks_cis_SUSE_15* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_15_H

