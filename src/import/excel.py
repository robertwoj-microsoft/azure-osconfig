from enum import Enum
from os import path
import openpyxl
import sys
import input_definitions
from model import CISBenchmark, FunctionArgument, Recommendation, CISModel, FunctionCall

class CISLevel(Enum):
    L1 = 1
    L2 = 2

class MachineType(Enum):
    Server = 1
    Workstation = 2

RECOMMENDATION_IDX = 1      # Column B
SUMMARY_IDX = 2             # Column C
ASSESMENT_STATUS_IDX = 3    # Column D
DESCRIPTION_IDX = 4         # Column E

def load_recommendation(row) -> Recommendation:
    return Recommendation(
        row[RECOMMENDATION_IDX],
        row[SUMMARY_IDX],
        row[DESCRIPTION_IDX],
        # To be filled in, just placeholders for now
        FunctionCall("some function name"),
        FunctionCall("sce_bash", [FunctionArgument("check_file_perms"), FunctionArgument("/etc/passwd")]),
        FunctionCall("check_file_perms", [FunctionArgument("/etc/passwd"), FunctionArgument(int('777', 8))]))

def load_benchmark(sheet, level: CISLevel, machine_type: MachineType, distribution: str, distribution_version: str, version: str) -> CISBenchmark:
    benchmark = CISBenchmark(distribution, distribution_version, version, level.name, machine_type.name)

    for row in sheet.iter_rows(min_row=2, values_only=True):
        # Skip rows without recommendation number
        if row[RECOMMENDATION_IDX] is None:
            continue
        # Skip rows without 'Automated' assessment status
        if row[ASSESMENT_STATUS_IDX] != 'Automated':
            continue

        # Load a single recommendation and store in the result
        benchmark.recommendations.append(load_recommendation(row))

    return benchmark

def parse_CIS_Excel(input_directory: str) -> CISModel:
    if not path.isdir(input_directory):
        print(f"Error: {input_directory} must be a directory.")
        sys.exit(1)

    model = CISModel()
    for input_definition in input_definitions.get_input_definitions():
        if input_definition.benchmark_name != "cis":
            print(f"Error: Unsupported benchmark name: {input_definition.benchmark_name}")
            sys.exit(1)

        print(f"Processing file: {path.join(input_directory, input_definition.file_name)}")

        # List all sheet names in the workbook
        workbook = openpyxl.load_workbook(path.join(input_directory, input_definition.file_name))

        if 'Level 1 - Server' in workbook.sheetnames:
            model.benchmarks.append(load_benchmark(workbook["Level 1 - Server"], CISLevel.L1, MachineType.Server, input_definition.distribution_name, input_definition.distribution_version, input_definition.benchmark_version))

        if 'Level 1 - Workstation' in workbook.sheetnames:
            model.benchmarks.append(load_benchmark(workbook["Level 1 - Workstation"], CISLevel.L1, MachineType.Workstation, input_definition.distribution_name, input_definition.distribution_version, input_definition.benchmark_version))

        if 'Level 2 - Server' in workbook.sheetnames:
            model.benchmarks.append(load_benchmark(workbook["Level 2 - Server"], CISLevel.L2, MachineType.Server, input_definition.distribution_name, input_definition.distribution_version, input_definition.benchmark_version))

        if 'Level 2 - Workstation' in workbook.sheetnames:
            model.benchmarks.append(load_benchmark(workbook["Level 2 - Workstation"], CISLevel.L1, MachineType.Workstation, input_definition.distribution_name, input_definition.distribution_version, input_definition.benchmark_version))
    return model
