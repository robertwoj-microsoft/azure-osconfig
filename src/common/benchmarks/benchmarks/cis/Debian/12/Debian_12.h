#ifndef BENCHMARKS_CIS_DEBIAN_12_H
#define BENCHMARKS_CIS_DEBIAN_12_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v1.1.0/Debian_12_v1.1.0.h"

struct benchmarks_cis_Debian_12
{
    struct benchmarks_cis_Debian_12_v1_1_0 rule_v1_1_0;
};

struct benchmarks_cis_Debian_12 benchmarks_cis_Debian_12_init();
benchmark_result_t benchmarks_cis_Debian_12_audit(const struct benchmarks_cis_Debian_12* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_12_remediate(const struct benchmarks_cis_Debian_12* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_12_H

