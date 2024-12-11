from dataclasses import dataclass, field, asdict
from typing import List

@dataclass
class FunctionArgument:
    value: str | int | bool # Adjust supported types as needed

@dataclass
class FunctionCall:
    name: str
    args: List[FunctionArgument] = field(default_factory=list)

# This class represents a single entry in the MOF file
@dataclass
class Recommendation:
    recommendation_id: str
    summary: str
    description: str
    # Run before remediation
    init: FunctionCall = None
    audit: FunctionCall = None
    remediation: FunctionCall = None
    # Default values for user-facing parameters
    external_params: List[FunctionArgument] = field(default_factory=list)

# This class represents the entire MOF file, which is a list of RPCMethod objects
@dataclass
class CISBenchmark:
    distribution: str
    distribution_version: str
    version: str
    level: str
    machine_type: str
    recommendations : List[Recommendation] = field(default_factory=list)

# This class represents a set of benchmarks split by specific versions
@dataclass
class CISModel:
    benchmarks: List[CISBenchmark] = field(default_factory=list)
