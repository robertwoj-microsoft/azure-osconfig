#ifndef BENCHMARKS_CIS_UBUNTU_H
#define BENCHMARKS_CIS_UBUNTU_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../benchmarks_common.h"

#include "16.04/Ubuntu_16.04.h"
#include "18.04/Ubuntu_18.04.h"
#include "20.04/Ubuntu_20.04.h"
#include "22.04/Ubuntu_22.04.h"
#include "24.04/Ubuntu_24.04.h"

struct benchmarks_cis_Ubuntu
{
    struct benchmarks_cis_Ubuntu_16_04 rule_16_04;
    struct benchmarks_cis_Ubuntu_18_04 rule_18_04;
    struct benchmarks_cis_Ubuntu_20_04 rule_20_04;
    struct benchmarks_cis_Ubuntu_22_04 rule_22_04;
    struct benchmarks_cis_Ubuntu_24_04 rule_24_04;
};

struct benchmarks_cis_Ubuntu benchmarks_cis_Ubuntu_init();
benchmark_result_t benchmarks_cis_Ubuntu_audit(const struct benchmarks_cis_Ubuntu* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_Ubuntu_remediate(const struct benchmarks_cis_Ubuntu* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_UBUNTU_H

