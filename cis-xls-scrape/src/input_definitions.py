from dataclasses import dataclass

@dataclass
class InputDefinition:
    file_name: str
    benchmark_name: str
    benchmark_version: str
    distribution_name: str
    distribution_version: str

    # Excel column indices:
    recommendation_idx: int
    title_idx: int
    assesment_status_idx: int
    remediation_procedure_idx: int
    audit_procedure_idx: int

def get_input_definitions() -> list[InputDefinition]:
    return [
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_16.04_LTS_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Ubuntu', '16.04', 1, 2, 3, 7, 8),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_18.04_LTS_Benchmark_v2.2.0.xlsx', 'cis', 'v2.2.0', 'Ubuntu', '18.04', 1, 2, 3, 7, 8),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_20.04_LTS_Benchmark_v2.0.1.xlsx', 'cis', 'v2.0.1', 'Ubuntu', '20.04', 1, 2, 3, 7, 8),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_22.04_LTS_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Ubuntu', '22.04', 1, 2, 3, 7, 8),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_24.04_LTS_Benchmark_v1.0.0.xlsx', 'cis', 'v1.0.0', 'Ubuntu', '24.04', 1, 2, 3, 7, 8),

        InputDefinition('RHEL/CIS_Red_Hat_Enterprise_Linux_7_Benchmark_v4.0.0.xlsx', 'cis', 'v4.0.0', 'RHEL', '7', 1, 2, 3, 7, 8),
        InputDefinition('RHEL/CIS_Red_Hat_Enterprise_Linux_9_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'RHEL', '9', 1, 2, 3, 7, 8),

        InputDefinition('SuSE/CIS_SUSE_Linux_Enterprise_12_Benchmark_v3.1.0-CERT.xlsx', 'cis', 'v3.1.0', 'SUSE', '12', 1, 2, 3, 7, 8),
        InputDefinition('SuSE/CIS_SUSE_Linux_Enterprise_15_Benchmark_v1.1.1.xlsx', 'cis', 'v1.1.1', 'SUSE', '15', 1, 2, 3, 7, 8),

        InputDefinition('Rocky/CIS_Rocky_Linux_8_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Rocky', '8', 1, 2, 3, 7, 8),
        InputDefinition('Rocky/CIS_Rocky_Linux_9_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Rocky', '9', 1, 2, 3, 7, 8),

        InputDefinition('Oracle/CIS_Oracle_Linux_7_Benchmark_v4.0.0.xlsx', 'cis', 'v4.0.0', 'Oracle', '7', 1, 2, 3, 7, 8),
        InputDefinition('Oracle/CIS_Oracle_Linux_8_Benchmark_v3.0.0.xlsx', 'cis', 'v3.0.0', 'Oracle', '8', 1, 2, 3, 7, 8),
        InputDefinition('Oracle/CIS_Oracle_Linux_9_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Oracle', '9', 1, 2, 3, 7, 8),

        InputDefinition('Debian/CIS_Debian_Linux_10_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Debian', '10', 1, 2, 3, 7, 8),
        InputDefinition('Debian/CIS_Debian_Linux_11_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Debian', '11', 1, 2, 3, 7, 8),
        InputDefinition('Debian/CIS_Debian_Linux_12_Benchmark_v1.1.0.xlsx', 'cis', 'v1.1.0', 'Debian', '12', 1, 2, 3, 7, 8),

        InputDefinition('CentOS/CIS_CentOS_Linux_7_Benchmark_v4.0.0.xlsx', 'cis', 'v4.0.0', 'CentOS', '7', 1, 2, 3, 7, 8),
        InputDefinition('CentOS/CIS_CentOS_Linux_8_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'CentOS', '8', 1, 2, 3, 7, 8),

        InputDefinition('Azure/CIS_AKS_Optimized_Azure_Linux_Benchmark_v1.0.0.xlsx', 'cis', 'v1.0.0', 'Azure', '3', 1, 2, 3, 7, 8), # Which version of Azure Linux?

        InputDefinition('Alma/CIS_AlmaLinux_OS_8_Benchmark_v3.0.0.xlsx', 'cis', 'v3.0.0', 'Alma', '8', 1, 2, 3, 7, 8),
        InputDefinition('Alma/CIS_AlmaLinux_OS_9_Benchmark_v2.0.0.xlsx', 'cis', 'v3.0.0', 'Alma', '9', 1, 2, 3, 7, 8),

        InputDefinition('FreeBSD/CIS_FreeBSD_14_Benchmark_v1.0.0.xlsx', 'cis', 'v1.0.0', 'FreeBSD', '14', 1, 2, 3, 7, 8),
    ]