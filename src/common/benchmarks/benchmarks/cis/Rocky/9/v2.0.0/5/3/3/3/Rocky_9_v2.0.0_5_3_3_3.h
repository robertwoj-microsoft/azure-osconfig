#ifndef BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_3_3_3_H
#define BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_3_3_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "1/Rocky_9_v2.0.0_5_3_3_3_1.h"
#include "2/Rocky_9_v2.0.0_5_3_3_3_2.h"
#include "3/Rocky_9_v2.0.0_5_3_3_3_3.h"

struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3
{
    struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3_1 rule_1;
    struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3_2 rule_2;
    struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3_3 rule_3;
};

struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3 benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3_init();
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3_audit(const struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3_remediate(const struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_3_3_3_H

