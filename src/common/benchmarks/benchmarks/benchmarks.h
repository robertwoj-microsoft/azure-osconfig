#ifndef BENCHMARKS_H
#define BENCHMARKS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "benchmarks_common.h"

#include "cis/cis.h"

struct benchmarks
{
    struct benchmarks_cis rule_cis;
};

struct benchmarks benchmarks_init();
benchmark_result_t benchmarks_audit(const struct benchmarks* interface, const char* path, void* log);
benchmark_result_t benchmarks_remediate(const struct benchmarks* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_H

