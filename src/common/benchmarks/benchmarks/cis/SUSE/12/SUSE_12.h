#ifndef BENCHMARKS_CIS_SUSE_12_H
#define BENCHMARKS_CIS_SUSE_12_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v3.1.0/SUSE_12_v3.1.0.h"

struct benchmarks_cis_SUSE_12
{
    struct benchmarks_cis_SUSE_12_v3_1_0 rule_v3_1_0;
};

struct benchmarks_cis_SUSE_12 benchmarks_cis_SUSE_12_init();
benchmark_result_t benchmarks_cis_SUSE_12_audit(const struct benchmarks_cis_SUSE_12* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_SUSE_12_remediate(const struct benchmarks_cis_SUSE_12* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_SUSE_12_H

