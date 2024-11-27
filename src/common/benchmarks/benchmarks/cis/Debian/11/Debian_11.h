#ifndef BENCHMARKS_CIS_DEBIAN_11_H
#define BENCHMARKS_CIS_DEBIAN_11_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../benchmarks_common.h"

#include "v2.0.0/Debian_11_v2.0.0.h"

struct benchmarks_cis_Debian_11
{
    struct benchmarks_cis_Debian_11_v2_0_0 rule_v2_0_0;
};

struct benchmarks_cis_Debian_11 benchmarks_cis_Debian_11_init();
benchmark_result_t benchmarks_cis_Debian_11_audit(const struct benchmarks_cis_Debian_11* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_11_remediate(const struct benchmarks_cis_Debian_11* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_11_H

