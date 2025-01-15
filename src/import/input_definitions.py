from dataclasses import dataclass

@dataclass
class InputDefinition:
    file_name: str
    benchmark_name: str
    benchmark_version: str
    distribution_name: str
    distribution_version: str

# Static list of CIS benchmarks we're planning to support, for now includes all but FreeBSD that was available in the package.
def get_input_definitions() -> list[InputDefinition]:
    return [
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_16.04_LTS_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Ubuntu', '16.04'),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_18.04_LTS_Benchmark_v2.2.0.xlsx', 'cis', 'v2.2.0', 'Ubuntu', '18.04'),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_20.04_LTS_Benchmark_v2.0.1.xlsx', 'cis', 'v2.0.1', 'Ubuntu', '20.04'),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_22.04_LTS_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Ubuntu', '22.04'),
        InputDefinition('Ubuntu/CIS_Ubuntu_Linux_24.04_LTS_Benchmark_v1.0.0.xlsx', 'cis', 'v1.0.0', 'Ubuntu', '24.04'),

        InputDefinition('RHEL/CIS_Red_Hat_Enterprise_Linux_7_Benchmark_v4.0.0.xlsx', 'cis', 'v4.0.0', 'RHEL', '7'),
        InputDefinition('RHEL/CIS_Red_Hat_Enterprise_Linux_8_Benchmark_v3.0.0.xlsx', 'cis', 'v4.0.0', 'RHEL', '8'),
        InputDefinition('RHEL/CIS_Red_Hat_Enterprise_Linux_9_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'RHEL', '9'),

        InputDefinition('SuSE/CIS_SUSE_Linux_Enterprise_12_Benchmark_v3.1.0.xlsx', 'cis', 'v3.1.0', 'SUSE', '12'),
        InputDefinition('SuSE/CIS_SUSE_Linux_Enterprise_15_Benchmark_v1.1.1.xlsx', 'cis', 'v1.1.1', 'SUSE', '15'),

        InputDefinition('Rocky/CIS_Rocky_Linux_8_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Rocky', '8'),
        InputDefinition('Rocky/CIS_Rocky_Linux_9_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Rocky', '9'),

        InputDefinition('Oracle/CIS_Oracle_Linux_7_Benchmark_v4.0.0.xlsx', 'cis', 'v4.0.0', 'Oracle', '7'),
        InputDefinition('Oracle/CIS_Oracle_Linux_8_Benchmark_v3.0.0.xlsx', 'cis', 'v3.0.0', 'Oracle', '8'),
        InputDefinition('Oracle/CIS_Oracle_Linux_9_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Oracle', '9'),

        InputDefinition('Debian/CIS_Debian_Linux_10_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Debian', '10'),
        InputDefinition('Debian/CIS_Debian_Linux_11_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Debian', '11'),
        InputDefinition('Debian/CIS_Debian_Linux_12_Benchmark_v1.1.0.xlsx', 'cis', 'v1.1.0', 'Debian', '12'),

        InputDefinition('CentOS/CIS_CentOS_Linux_7_Benchmark_v4.0.0.xlsx', 'cis', 'v4.0.0', 'CentOS', '7'),
        InputDefinition('CentOS/CIS_CentOS_Linux_8_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'CentOS', '8'),

        InputDefinition('Azure/CIS_AKS_Optimized_Azure_Linux_Benchmark_v1.0.0.xlsx', 'cis', 'v1.0.0', 'Azure', '2'),

        InputDefinition('Alma/CIS_AlmaLinux_OS_8_Benchmark_v3.0.0.xlsx', 'cis', 'v3.0.0', 'Alma', '8'),
        InputDefinition('Alma/CIS_AlmaLinux_OS_9_Benchmark_v2.0.0.xlsx', 'cis', 'v2.0.0', 'Alma', '9'),
    ]