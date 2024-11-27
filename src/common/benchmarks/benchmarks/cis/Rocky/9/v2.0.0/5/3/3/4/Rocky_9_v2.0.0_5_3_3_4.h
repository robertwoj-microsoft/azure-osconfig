#ifndef BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_3_3_4_H
#define BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_3_3_4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../../benchmarks_common.h"

#include "1/Rocky_9_v2.0.0_5_3_3_4_1.h"
#include "2/Rocky_9_v2.0.0_5_3_3_4_2.h"
#include "3/Rocky_9_v2.0.0_5_3_3_4_3.h"
#include "4/Rocky_9_v2.0.0_5_3_3_4_4.h"

struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4
{
    struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_1 rule_1;
    struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_2 rule_2;
    struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_3 rule_3;
    struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_4 rule_4;
};

struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4 benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_init();
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_audit(const struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_remediate(const struct benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_9_V2_0_0_5_3_3_4_H

