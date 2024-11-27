#ifndef BENCHMARKS_CIS_ROCKY_8_V2_0_0_6_H
#define BENCHMARKS_CIS_ROCKY_8_V2_0_0_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../benchmarks_common.h"

#include "1/Rocky_8_v2.0.0_6_1.h"
#include "2/Rocky_8_v2.0.0_6_2.h"

struct benchmarks_cis_Rocky_8_v2_0_0_6
{
    struct benchmarks_cis_Rocky_8_v2_0_0_6_1 rule_1;
    struct benchmarks_cis_Rocky_8_v2_0_0_6_2 rule_2;
};

struct benchmarks_cis_Rocky_8_v2_0_0_6 benchmarks_cis_Rocky_8_v2_0_0_6_init();
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_6_audit(const struct benchmarks_cis_Rocky_8_v2_0_0_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_6_remediate(const struct benchmarks_cis_Rocky_8_v2_0_0_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_8_V2_0_0_6_H

