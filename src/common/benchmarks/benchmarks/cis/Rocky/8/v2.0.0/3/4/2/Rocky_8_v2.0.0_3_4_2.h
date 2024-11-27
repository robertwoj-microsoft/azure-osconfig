#ifndef BENCHMARKS_CIS_ROCKY_8_V2_0_0_3_4_2_H
#define BENCHMARKS_CIS_ROCKY_8_V2_0_0_3_4_2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../../../../benchmarks_common.h"

#include "1/Rocky_8_v2.0.0_3_4_2_1.h"
#include "2/Rocky_8_v2.0.0_3_4_2_2.h"
#include "3/Rocky_8_v2.0.0_3_4_2_3.h"
#include "4/Rocky_8_v2.0.0_3_4_2_4.h"
#include "5/Rocky_8_v2.0.0_3_4_2_5.h"

struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2
{
    struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2_1 rule_1;
    struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2_2 rule_2;
    struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2_3 rule_3;
    struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2_4 rule_4;
    struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2_5 rule_5;
};

struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2 benchmarks_cis_Rocky_8_v2_0_0_3_4_2_init();
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_3_4_2_audit(const struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Rocky_8_v2_0_0_3_4_2_remediate(const struct benchmarks_cis_Rocky_8_v2_0_0_3_4_2* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_ROCKY_8_V2_0_0_3_4_2_H

