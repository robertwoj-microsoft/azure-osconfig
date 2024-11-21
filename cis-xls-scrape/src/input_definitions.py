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

input_definitions = [
    InputDefinition('Ubuntu/CIS_Ubuntu_Linux_22.04_LTS_Benchmark_v2.0.0-Certification.xlsx', 'cis', 'v2.0.0', 'Ubuntu', '22.04', 1, 2, 3, 12, 13),
    InputDefinition('RHEL/CIS_Red_Hat_Enterprise_Linux_9_Benchmark_v2.0.0-Certification.xlsx', 'cis', 'v2.0.0', 'RHEL', '9', 1, 2, 3, 12, 13),
]