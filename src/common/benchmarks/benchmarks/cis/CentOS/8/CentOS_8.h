#ifndef BENCHMARKS_CIS_CENTOS_8_H
#define BENCHMARKS_CIS_CENTOS_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v2.0.0/CentOS_8_v2.0.0.h"

struct benchmarks_cis_CentOS_8
{
    struct benchmarks_cis_CentOS_8_v2_0_0 rule_v2_0_0;
};

struct benchmarks_cis_CentOS_8 benchmarks_cis_CentOS_8_init();
benchmark_result_t benchmarks_cis_CentOS_8_audit(const struct benchmarks_cis_CentOS_8* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_8_remediate(const struct benchmarks_cis_CentOS_8* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_8_H

