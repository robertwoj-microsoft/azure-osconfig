import json
from typing import List
from model import CISBenchmark, FunctionArgument, FunctionCall, Recommendation
import base64

def arg_to_json(arg: FunctionArgument) -> str:
    if isinstance(arg.value, str):
        return f'"{arg.value}"'
    return arg.value

def to_json(func: FunctionCall) -> str:
    obj = {}
    obj["name"] = func.name
    args = []
    for arg in func.args:
        args.append(arg.value)
    obj["args"] = args
    return json.dumps(obj)

def to_mof(distribution: str, distribution_version: str, version: str, level: str, machine_type: str, recommendation: Recommendation) -> str:
    recommendation_id_path = recommendation.recommendation_id.replace(".", "/")
    payload_key = f"/cis/{distribution}/{distribution_version}/{version}/{level}/{machine_type}/{recommendation_id_path}".replace(".", "_")
    output = f'instance of OsConfigResource {{\n'
    output += f'    ResourceID = "{recommendation.summary}";\n'
    output += f'    PayloadKey = "{payload_key}";\n'
    output += f'    RuleId = "PLACEHOLDER";\n'
    output += f'    ComponentName = "SecurityBaseline";\n'
    output += f'    InitObjectName = "{base64.b64encode(to_json(recommendation.init).encode()).decode()}";\n'
    output += f'    ReportedObjectName = "{base64.b64encode(to_json(recommendation.audit).encode()).decode()}";\n'
    output += f'    ExpectedObjectValue = "PASS";\n'
    output += f'    DesiredObjectName = "{base64.b64encode(to_json(recommendation.remediation).encode()).decode()}";\n'
    output += f'    DesiredObjectValue = "";\n'
    output += f'    ModuleName = "GuestConfiguration";\n'
    output += f'    ModuleVersion = "1.0.0";\n'
    output += f'    ConfigurationName = "CIS_for_Linux";\n'
    output += f'    SourceInfo = "::4::5::OsConfigResource";\n'
    output += f'}};\n'
    return output

def dump_mof(benchmarks: List[CISBenchmark], output_file: str):
    with open(output_file, 'w') as f:
        for benchmark in benchmarks:
            for recommendation in benchmark.recommendations:
                f.write(to_mof(benchmark.distribution, benchmark.distribution_version, benchmark.version, benchmark.level, benchmark.machine_type, recommendation))
                f.write("\n")