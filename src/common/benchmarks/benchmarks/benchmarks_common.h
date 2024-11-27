#ifndef BENCHMARKS_COMMON_H
#define BENCHMARKS_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <Logging.h>

typedef enum
{
    BENCHMARK_COMPLIANT,
    BENCHMARK_NON_COMPLIANT,
    BENCHMARK_FAILED,
    BENCHMARK_NOT_APPLICABLE
} benchmark_result_t;

typedef benchmark_result_t (*bench_action_t)(void*);

#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_COMMON_H

