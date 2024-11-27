#ifndef BENCHMARKS_CIS_H
#define BENCHMARKS_CIS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../benchmarks_common.h"

#include "Alma/Alma.h"
#include "Azure/Azure.h"
#include "CentOS/CentOS.h"
#include "Debian/Debian.h"
#include "FreeBSD/FreeBSD.h"
#include "Oracle/Oracle.h"
#include "RHEL/RHEL.h"
#include "Rocky/Rocky.h"
#include "SUSE/SUSE.h"
#include "Ubuntu/Ubuntu.h"

struct benchmarks_cis
{
    struct benchmarks_cis_Alma rule_Alma;
    struct benchmarks_cis_Azure rule_Azure;
    struct benchmarks_cis_CentOS rule_CentOS;
    struct benchmarks_cis_Debian rule_Debian;
    struct benchmarks_cis_FreeBSD rule_FreeBSD;
    struct benchmarks_cis_Oracle rule_Oracle;
    struct benchmarks_cis_RHEL rule_RHEL;
    struct benchmarks_cis_Rocky rule_Rocky;
    struct benchmarks_cis_SUSE rule_SUSE;
    struct benchmarks_cis_Ubuntu rule_Ubuntu;
};

struct benchmarks_cis benchmarks_cis_init();
benchmark_result_t benchmarks_cis_audit(const struct benchmarks_cis* interface, const char* path, void* log);
benchmark_result_t benchmarks_cis_remediate(const struct benchmarks_cis* interface, const char* path, void* log);
#ifdef __cplusplus
}
#endif

#endif // BENCHMARKS_CIS_H

