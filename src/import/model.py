from dataclasses import dataclass, field, asdict
from typing import List

@dataclass
class FunctionArgument:
    value: str | int | bool # Adjust supported types as needed

@dataclass
class FunctionCall:
    name: str
    args: List[FunctionArgument] = field(default_factory=list)

    def to_dict(self):
        print("xxx")
        return {
            self.name: [arg.value for arg in self.args]
        }

@dataclass
class OrExpression:
    expressions: List['Expression'] = field(default_factory=list)

@dataclass
class AndExpression:
    expressions: List['Expression'] = field(default_factory=list)

@dataclass
class NotExpression:
    expression: 'Expression'

@dataclass
class Expression:
    expression: FunctionCall | OrExpression | AndExpression | NotExpression

# This class represents a single entry in the MOF file
@dataclass
class Recommendation:
    recommendation_id: str
    summary: str
    description: str
    # Run before remediation
    init: FunctionCall | OrExpression | AndExpression | NotExpression = None
    audit: FunctionCall | OrExpression | AndExpression | NotExpression = None
    remediation: FunctionCall | OrExpression | AndExpression | NotExpression = None
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


def dict_factory(model):
    if isinstance(model, FunctionCall):
        return {
            model.name: [arg.value for arg in model.args]
        }
    elif isinstance(model, OrExpression):
        return {"OR": [expr.to_dict() for expr in model.expression.expressions]}
    elif isinstance(model, AndExpression):
        return {"AND": [expr.to_dict() for expr in model.expression.expressions]}
    elif isinstance(model, NotExpression):
        return {"NOT": model.expression.expression.to_dict()}
    else:
        asdict(model)