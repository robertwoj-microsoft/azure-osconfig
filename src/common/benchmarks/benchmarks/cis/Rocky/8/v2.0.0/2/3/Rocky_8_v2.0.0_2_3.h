#ifndef BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_3_H
#define BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../benchmarks_common.h"

#include "1/Rocky_8_v2.0.0_2_3_1.h"
#include "3/Rocky_8_v2.0.0_2_3_3.h"
#include "4/Rocky_8_v2.0.0_2_3_4.h"
#include "5/Rocky_8_v2.0.0_2_3_5.h"

struct benchmarks_cis_Rocky_8_v2_0_0_2_3
{
    struct benchmarks_cis_Rocky_8_v2_0_0_2_3_1 rule_1;
    struct benchmarks_cis_Rocky_8_v2_0_0_2_3_3 rule_3;
    struct benchmarks_cis_Rocky_8_v2_0_0_2_3_4 rule_4;
    struct benchmarks_cis_Rocky_8_v2_0_0_2_3_5 rule_5;
};

struct benchmarks_cis_Rocky_8_v2_0_0_2_3 benchmarks_cis_Rocky_8_v2_0_0_2_3_init();
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_2_3_audit(const struct benchmarks_cis_Rocky_8_v2_0_0_2_3* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_2_3_remediate(const struct benchmarks_cis_Rocky_8_v2_0_0_2_3* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_8_V2_0_0_2_3_H

