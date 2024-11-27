#ifndef BENCHMARKS_CIS_CENTOS_H
#define BENCHMARKS_CIS_CENTOS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "7/CentOS_7.h"
#include "8/CentOS_8.h"

struct benchmarks_cis_CentOS
{
    struct benchmarks_cis_CentOS_7 rule_7;
    struct benchmarks_cis_CentOS_8 rule_8;
};

struct benchmarks_cis_CentOS benchmarks_cis_CentOS_init();
benchmark_result_t benchmarks_cis_CentOS_audit(const struct benchmarks_cis_CentOS* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_CentOS_remediate(const struct benchmarks_cis_CentOS* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_CENTOS_H

