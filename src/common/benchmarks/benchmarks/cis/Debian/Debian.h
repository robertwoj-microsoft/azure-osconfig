#ifndef BENCHMARKS_CIS_DEBIAN_H
#define BENCHMARKS_CIS_DEBIAN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "10/Debian_10.h"
#include "11/Debian_11.h"
#include "12/Debian_12.h"

struct benchmarks_cis_Debian
{
    struct benchmarks_cis_Debian_10 rule_10;
    struct benchmarks_cis_Debian_11 rule_11;
    struct benchmarks_cis_Debian_12 rule_12;
};

struct benchmarks_cis_Debian benchmarks_cis_Debian_init();
benchmark_result_t benchmarks_cis_Debian_audit(const struct benchmarks_cis_Debian* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Debian_remediate(const struct benchmarks_cis_Debian* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_DEBIAN_H

