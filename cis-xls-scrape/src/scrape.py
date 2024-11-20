from importlib.metadata import distribution
import openpyxl
import os
import sys
from dataclasses import dataclass, field, asdict
from typing import List, Optional
import yaml
from enum import Enum
import input_definitions

class ProcedureType(Enum):
    AUDIT = 1
    REMEDIATION = 2

@dataclass
class OpenAPISpec:
    openapi: str = "3.0.0"
    info: dict = field(default_factory=lambda: {
        "title": "CIS for Linux osconfig module API",
        "description": "Aim of this API is to provide visualisation for the CIS for Linux osconfig module recommendations",
        "version": "1.0.0"
    })
    paths: dict = field(default_factory=dict)
    components: dict = field(default_factory=dict)
    tags: List[dict] = field(default_factory=list)
    servers: List[dict] = "http://localhost:8080"

@dataclass
class BashScriptSchema:
    type: str = "string"
    title: str = "Bash script content"
    description: str = "The content of the bash script"
    example: str = "echo 'Hello, World!'"

@dataclass
class Recommendation:
    path: str
    title: str
    description: str
    rationale: str
    remediation_procedure: Optional[str] = None
    audit_procedure: Optional[str] = None

@dataclass
class RecommendationNumberSchema:
    type: str = "string"
    title: str = "Recommendation number"
    description: str = "CIS recommendation numbers are dot-separated numbers that uniquely identify a recommendation"
    example: str = "1.1.1"

@dataclass
class RecommendationTitleSchema:
    type: str = "string"
    title: str = "Recommendation title"
    description: str = "The title of the recommendation"
    example: str = "Ensure mounting of cramfs filesystems is disabled"

@dataclass
class RecommendationDescriptionSchema:
    type: str = "string"
    title: str = "Recommendation description"
    description: str = "The description of the recommendation"
    example: str = "The cramfs filesystem type is a compressed read-only Linux filesystem embedded in small footprint systems. A cramfs image can be used without having to first decompress the image. The cramfs image is read-only, and cannot be modified. The cramfs filesystem type is being phased out in favor of squashfs, which provides greater flexibility and the ability to be mounted read-write. The cramfs filesystem type should be disabled unless required by your organization."

@dataclass
class RecommendationRationaleSchema:
    type: str = "string"
    title: str = "Recommendation rationale"
    description: str = "The rationale behind the recommendation"
    example: str = "The cramfs filesystem type is a compressed read-only Linux filesystem embedded in small footprint systems. A cramfs image can be used without having to first decompress the image. The cramfs image is read-only, and cannot be modified. The cramfs filesystem type is being phased out in favor of squashfs, which provides greater flexibility and the ability to be mounted read-write. The cramfs filesystem type should be disabled unless required by your organization."


@dataclass
class RecommendationSchema:
    type: str = "object"
    properties: dict = field(default_factory=lambda: {
        "number": {"$ref": "#/components/schemas/RecommendationNumberSchema"},
        "title": {"$ref": "#/components/schemas/RecommendationTitleSchema"},
        "description": {"$ref": "#/components/schemas/RecommendationDescriptionSchema"},
        "rationale": {"$ref": "#/components/schemas/RecommendationRationaleSchema"},
        "remediation_procedure": {"$ref": "#/components/schemas/BashScript"},
        "audit_procedure": {"$ref": "#/components/schemas/BashScript"}
    })
    required: List[str] = field(default_factory=lambda: ["number", "title", "description", "rationale"])

@dataclass
class Tag:
    name: str
    description: str

    def __hash__(self):
        return hash(self.name)

@dataclass
class Method:
    summary: str
    operationId: str
    tags: List[str]
    # requestBody: dict
    responses: dict

tags = {
    Tag(name="Audit", description="Audit recommendations"),
    Tag(name="Remediation", description="Remediation recommendations"),
    Tag(name="CIS", description="Center for Internet Security"),
    Tag(name="CIS-L1", description="CIS Level 1"),
    Tag(name="CIS-L1-Server", description="CIS Level 1 Server"),
    Tag(name="CIS-L1-Workstation", description="CIS Level 1 Server"),
    Tag(name="CIS-L2-Server", description="CIS Level 2 Server"),
    Tag(name="CIS-L2-Workstation", description="CIS Level 2 Server")
    }
paths = {}

api = OpenAPISpec()
api.components['schemas'] = {
    "RecommendationNumberSchema": RecommendationNumberSchema(),
    "RecommendationTitleSchema": RecommendationTitleSchema(),
    "RecommendationDescriptionSchema": RecommendationDescriptionSchema(),
    "RecommendationRationaleSchema": RecommendationRationaleSchema(),
    "Recommendation": RecommendationSchema(),
    "BashScript": BashScriptSchema()
}
api.tags = tags




def make_audit_method(title:str, number: str, category: str, machine_type: str, input_definition):
    return Method(
        summary=title,
        operationId=f"audit.cis.{number}",
        tags=["Audit", "CIS", f"CIS-{category}", f"CIS-{category}-{machine_type}", input_definition.distribution_name, f"{input_definition.distribution_name}-{input_definition.distribution_version}"],
        # requestBody={"$ref": "#/components/schemas/Recommendation"},
        responses={
            "200": {
                "description": "Compliant"
            },
            "400": {
                "description": "Non-compliant"
            },
            "500": {
                "description": "Audit was not performed due to an error"
            }
        }
    )




def make_remediation_method(title:str, number: str, category: str, machine_type: str, input_definition):
    return Method(
        summary=title,
        operationId=f"remediation.cis.{number}",
        tags=["Remediation", "CIS", f"CIS-{category}", f"CIS-{category}-{machine_type}", input_definition.distribution_name, f"{input_definition.distribution_name}-{input_definition.distribution_version}"],
        # requestBody={"$ref": "#/components/schemas/Recommendation"},
        responses={
            "200": {
                "description": "Remediation succeeded"
            },
            "500": {
                "description": "Remediation was not performed due to an error"
            }
        }
    )



def update_method_tags(api_path: str, method: str, category: str, machine_type: str, input_definition):
    existing_tags = {tag for tag in paths[api_path][method].tags}
    existing_tags.add("CIS")
    existing_tags.add(f"CIS-{category}")
    existing_tags.add(f"CIS-{category}-{machine_type}")
    existing_tags.add(input_definition.distribution_name)
    existing_tags.add(f"{input_definition.distribution_name}-{input_definition.distribution_version}")
    paths[api_path][method].tags = list(existing_tags)




def load_recommendation(row, category: str, machine_type: str, input_definition, procedure_type: ProcedureType):
    recommendation_number = row[input_definition.recommendation_idx]
    recommendation_path = row[input_definition.recommendation_idx].replace('.', '/')
    title = row[input_definition.title_idx]

    # Create the recommendation subdirectory path
    subdirectory_path = os.path.join(output_directory, recommendation_path)

    # Recursively create the subdirectory
    os.makedirs(subdirectory_path, exist_ok=True)

    api_path = f"/{input_definition.benchmark_name}/{input_definition.benchmark_version}/{recommendation_path}"
    # print(f"{recommendation_number} {distribution} {version}")
    if api_path not in paths:
        paths[api_path] = {}

    procedure_idx = None
    procedure_file_path = None
    match procedure_type:
        case ProcedureType.AUDIT:
            procedure_idx = input_definition.audit_procedure_idx
            procedure_file_path = os.path.join(subdirectory_path, 'audit_procedure.sh')
        case ProcedureType.REMEDIATION:
            procedure_idx = input_definition.remediation_procedure_idx
            procedure_file_path = os.path.join(subdirectory_path, 'remediation_procedure.sh')

    if not row[procedure_idx]:
        return

    # Extract text between ``` delimiters in the procedure field
    procedure = row[procedure_idx]
    script_start = procedure.find('```') + 3
    script_end = procedure.rfind('```')
    if script_start == -1 or script_end == -1:
        print(f"Note: Missing remediation script for {recommendation_number} ({title}).")
        return

    procedure_content = procedure[script_start:script_end].strip()
    # Write the extracted procedure to a file
    with open(procedure_file_path, 'w') as f:
        f.write(procedure_content)

    match procedure_type:
        case ProcedureType.AUDIT:
            method = make_audit_method(title, recommendation_number, category, machine_type, input_definition)
            if 'get' not in paths[api_path]:
                paths[api_path]['get'] = method
            else:
                update_method_tags(api_path, 'get', category, machine_type, input_definition)
        case ProcedureType.REMEDIATION:
            method = make_remediation_method(title, recommendation_number, category, machine_type, input_definition)
            if 'post' not in paths[api_path]:
                paths[api_path]['post'] = method
            else:
                update_method_tags(api_path, 'post', category, machine_type, input_definition)




def load_sheet_data(sheet, category: str, machine_type: str, distribution: str, version: str):
    distro_found = False
    distro_version_found = False
    for tag in tags:
        if tag.name == distribution:
            distro_found = True
        if tag.name == f"{distribution}-{version}":
            distro_version_found = True

    if not distro_found:
        tags.add(Tag(distribution, f"CIS recommendations for {distribution} distribution"))
    if not distro_version_found:
        tags.add(Tag(f"{distribution}-{version}", f"CIS recommendations for {distribution} {version}"))

    for row in sheet.iter_rows(min_row=2, values_only=True):
        # Skip rows without recommendation number
        if row[input_definition.recommendation_idx] is None:
            continue
        # Skip rows without 'Automated' assessment status
        if row[input_definition.assesment_status_idx] != 'Automated':
            continue

        load_recommendation(row, category, machine_type, input_definition, ProcedureType.AUDIT)
        load_recommendation(row, category, machine_type, input_definition, ProcedureType.REMEDIATION)



if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python scrape.py <input_file_path> <output_directory>")
        sys.exit(1)

    input_directory = sys.argv[1]
    output_directory = sys.argv[2]

    if not os.path.isdir(input_directory):
        print(f"Error: {input_directory} must be a directory.")
        sys.exit(1)

    if not os.path.isdir(output_directory):
        print(f"Error: {output_directory} must be a directory.")
        sys.exit(1)

    for input_definition in input_definitions.input_definitions:
        if input_definition.benchmark_name != "cis":
            print(f"Error: Unsupported benchmark name: {input_definition.benchmark_name}")
            sys.exit(1)

        print(f"Processing file: {os.path.join(input_directory, input_definition.file_name)}")

        # List all sheet names in the workbook
        workbook = openpyxl.load_workbook(os.path.join(input_directory, input_definition.file_name))
        sheet_names = workbook.sheetnames
        print("Available sheets:")
        for sheet_name in sheet_names:
            print(f"- {sheet_name}")

        # Load data from the specific sheets 'Level 1 - Server'
        if 'Level 1 - Server' in sheet_names:
            load_sheet_data(workbook["Level 1 - Server"], "L1", "Server", input_definition.distribution_name, input_definition.distribution_version)

        if 'Level 1 - Workstation' in sheet_names:
            load_sheet_data(workbook["Level 1 - Workstation"], "L1", "Workstation", input_definition.distribution_name, input_definition.distribution_version)

        if 'Level 2 - Server' in sheet_names:
            load_sheet_data(workbook["Level 2 - Server"], "L2", "Server", input_definition.distribution_name, input_definition.distribution_version)

        if 'Level 2 - Workstation' in sheet_names:
            load_sheet_data(workbook["Level 2 - Workstation"], "L2", "Workstation", input_definition.distribution_name, input_definition.distribution_version)

    api.paths = paths
    api.tags = list(tags)

    # Save the OpenAPI specification to a yaml file
    output_file_path = os.path.join(output_directory, 'openapi.yaml')
    with open(output_file_path, 'w') as f:
        yaml.dump(asdict(api), f)