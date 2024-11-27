#ifndef BENCHMARKS_CIS_ROCKY_9_V2_0_0_1_1_2_6_H
#define BENCHMARKS_CIS_ROCKY_9_V2_0_0_1_1_2_6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "2/Rocky_9_v2.0.0_1_1_2_6_2.h"
#include "3/Rocky_9_v2.0.0_1_1_2_6_3.h"
#include "4/Rocky_9_v2.0.0_1_1_2_6_4.h"

struct benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6
{
    struct benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6_2 rule_2;
    struct benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6_3 rule_3;
    struct benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6_4 rule_4;
};

struct benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6 benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6_init();
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6_audit(const struct benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6_remediate(const struct benchmarks_cis_Rocky_9_v2_0_0_1_1_2_6* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_9_V2_0_0_1_1_2_6_H

