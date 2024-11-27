#ifndef BENCHMARKS_CIS_UBUNTU_16_04_H
#define BENCHMARKS_CIS_UBUNTU_16_04_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v2.0.0/Ubuntu_16.04_v2.0.0.h"

struct benchmarks_cis_Ubuntu_16_04
{
    struct benchmarks_cis_Ubuntu_16_04_v2_0_0 rule_v2_0_0;
};

struct benchmarks_cis_Ubuntu_16_04 benchmarks_cis_Ubuntu_16_04_init();
benchmark_result_t benchmarks_cis_Ubuntu_16_04_audit(const struct benchmarks_cis_Ubuntu_16_04* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_16_04_remediate(const struct benchmarks_cis_Ubuntu_16_04* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_16_04_H

