#ifndef BENCHMARKS_CIS_UBUNTU_24_04_H
#define BENCHMARKS_CIS_UBUNTU_24_04_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v1.0.0/Ubuntu_24.04_v1.0.0.h"

struct benchmarks_cis_Ubuntu_24_04
{
    struct benchmarks_cis_Ubuntu_24_04_v1_0_0 rule_v1_0_0;
};

struct benchmarks_cis_Ubuntu_24_04 benchmarks_cis_Ubuntu_24_04_init();
benchmark_result_t benchmarks_cis_Ubuntu_24_04_audit(const struct benchmarks_cis_Ubuntu_24_04* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_24_04_remediate(const struct benchmarks_cis_Ubuntu_24_04* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_24_04_H

