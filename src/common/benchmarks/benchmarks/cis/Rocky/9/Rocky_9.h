#ifndef BENCHMARKS_CIS_ROCKY_9_H
#define BENCHMARKS_CIS_ROCKY_9_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v2.0.0/Rocky_9_v2.0.0.h"

struct benchmarks_cis_Rocky_9
{
    struct benchmarks_cis_Rocky_9_v2_0_0 rule_v2_0_0;
};

struct benchmarks_cis_Rocky_9 benchmarks_cis_Rocky_9_init();
benchmark_result_t benchmarks_cis_Rocky_9_audit(const struct benchmarks_cis_Rocky_9* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_9_remediate(const struct benchmarks_cis_Rocky_9* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_9_H

