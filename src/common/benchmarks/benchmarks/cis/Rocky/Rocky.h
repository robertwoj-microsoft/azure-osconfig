#ifndef BENCHMARKS_CIS_ROCKY_H
#define BENCHMARKS_CIS_ROCKY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "8/Rocky_8.h"
#include "9/Rocky_9.h"

struct benchmarks_cis_Rocky
{
    struct benchmarks_cis_Rocky_8 rule_8;
    struct benchmarks_cis_Rocky_9 rule_9;
};

struct benchmarks_cis_Rocky benchmarks_cis_Rocky_init();
benchmark_result_t benchmarks_cis_Rocky_audit(const struct benchmarks_cis_Rocky* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_remediate(const struct benchmarks_cis_Rocky* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_H

