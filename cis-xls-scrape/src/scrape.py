from hashlib import sha256
from importlib.metadata import distribution
import openpyxl
import os
import sys
from dataclasses import dataclass, field, asdict
from typing import List, Optional
import yaml
from enum import Enum
import input_definitions
from collections import deque

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

output_directory = None


def make_audit_method(title:str, number: str, category: str, machine_type: str, input_definition, procedure_hash: str):
    return Method(
        summary=title,
        operationId=procedure_hash,
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




def make_remediation_method(title:str, number: str, category: str, machine_type: str, input_definition, procedure_hash: str):
    return Method(
        summary=title,
        operationId=procedure_hash,
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
    subdirectory_path = os.path.join(output_directory, input_definition.benchmark_name, input_definition.benchmark_version, input_definition.distribution_name, input_definition.distribution_version, recommendation_path)

    # Recursively create the subdirectory
    os.makedirs(subdirectory_path, exist_ok=True)

    api_path = f"/{input_definition.benchmark_name}/{input_definition.benchmark_version}/{recommendation_path}"
    # print(f"{recommendation_number} {distribution} {version}")
    if api_path not in paths:
        paths[api_path] = {}

    procedure_idx = None
    # procedure_file_path = None
    if procedure_type == ProcedureType.AUDIT:
        procedure_idx = input_definition.audit_procedure_idx
        # procedure_file_path = os.path.join(subdirectory_path, 'audit_procedure.sh')
    elif procedure_type == ProcedureType.REMEDIATION:
        procedure_idx = input_definition.remediation_procedure_idx
        # procedure_file_path = os.path.join(subdirectory_path, 'remediation_procedure.sh')

    if not row[procedure_idx]:
        return

    # Extract text between ``` delimiters in the procedure field
    procedure = row[procedure_idx]
    script_start = procedure.find('```') + 3
    script_end = procedure.find('```', script_start)
    if script_start == -1 or script_end == -1:
        print(f"Note: Missing remediation script for {recommendation_number} ({title}).")
        return

    procedure_content = procedure[script_start:script_end].strip()
    procedure_hash = sha256(procedure_content.encode()).hexdigest()
    procedure_path = os.path.join(output_directory, 'actions', f"{procedure_hash}.sh")

    # Write the extracted procedure to a file
    if not os.path.isfile(procedure_path):
        with open(procedure_path, 'w') as f:
            f.write(procedure_content)

    if procedure_type == ProcedureType.AUDIT:
        linkname = os.path.join(subdirectory_path, 'audit.sh')
        if not os.path.exists(linkname):
            os.symlink(procedure_path, linkname)
        method = make_audit_method(title, recommendation_number, category, machine_type, input_definition, procedure_hash)
        if 'get' not in paths[api_path]:
            paths[api_path]['get'] = method
        else:
            update_method_tags(api_path, 'get', category, machine_type, input_definition)
    if procedure_type == ProcedureType.REMEDIATION:
        linkname = os.path.join(subdirectory_path, 'remediation.sh')
        if not os.path.exists(linkname):
            os.symlink(procedure_path, linkname)
        method = make_remediation_method(title, recommendation_number, category, machine_type, input_definition, procedure_hash)
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



def post_order_traversal(tree, node, visited):
    if node not in tree:
        return
    for child in tree[node]:
        post_order_traversal(tree, child, visited)
    visited.append(node)

def generate_c():
    def create_tree(paths):
        tree = {}
        for path in paths:
            parts = path.strip('/').split('/')
            current_level = tree
            for part in parts:
                if part not in current_level:
                    current_level[part] = {}
                current_level = current_level[part]
        return tree

    leaf_structures = set()
    parent_structures = dict()
    def traverse_tree(tree, path='bench', depth=0):
        for key, value in tree.items():
            traverse_tree(value, f"{path}_{key.replace('.', '_')}", depth + 1)

            # if depth == 0:
                # continue
            if not value:
                leaf_structures.add(f"{path}_{key.replace('.', '_')}")
            if path not in parent_structures:
                parent_structures[path] = set()
            parent_structures[path].add(f"{path}_{key.replace('.', '_')}")

    tree = create_tree(paths)
    traverse_tree(tree)

    # Generate a header file for the actions
    with open(os.path.join(output_directory, input_definition.benchmark_name, f"{input_definition.benchmark_name}.h"), 'w') as actions_h:
        # TODO: disclaimer, license, etc.
        actions_h.write(f"#ifndef {input_definition.benchmark_name.upper()}_ACTIONS_H\n")
        actions_h.write(f"#define {input_definition.benchmark_name.upper()}_ACTIONS_H\n\n")

        actions_h.write("#include \"../benchmarks_common.h\"\n\n")

        for struct_name in leaf_structures:
            actions_h.write(f"struct {struct_name}\n")
            actions_h.write("{\n")
            actions_h.write("    bench_action_t audit;\n")
            actions_h.write("    bench_action_t remediate;\n")
            actions_h.write("};\n\n")
            actions_h.write(f"struct {struct_name} {struct_name}_init(distro_type_t os);\n")
            actions_h.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name});\n\n")

        visited_nodes = []
        post_order_traversal(parent_structures, 'bench', visited_nodes)
        for struct_name in visited_nodes:
            if struct_name == 'bench':
                continue
            actions_h.write(f"struct {struct_name}\n")
            actions_h.write("{\n")
            for child in parent_structures[struct_name]:
                rule = child.replace(f"{struct_name}_", "")
                if rule[0].isdigit():
                    rule = f"r{rule}"
                actions_h.write(f"    struct {child} {rule};\n")
            actions_h.write("};\n\n")
            actions_h.write(f"struct {struct_name} {struct_name}_init(distro_type_t os);\n")
            actions_h.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name});\n\n")

        actions_h.write(f"#endif // {input_definition.benchmark_name.upper()}_ACTIONS_H\n\n")

    # Generate a source file for the actions
    with open(os.path.join(output_directory, input_definition.benchmark_name, f"{input_definition.benchmark_name}.c"), 'w') as actions_c:
        actions_c.write(f"#include \"{input_definition.benchmark_name}.h\"\n\n")

        for struct_name in leaf_structures:
            actions_c.write(f"static action_result_t {struct_name}_audit()\n")
            actions_c.write("{\n")
            actions_c.write("    // TODO: Implement audit\n")
            actions_c.write("    return BENCH_FAILED;\n")
            actions_c.write("}\n\n")

            actions_c.write(f"static action_result_t {struct_name}_remediate()\n")
            actions_c.write("{\n")
            actions_c.write("    // TODO: Implement remediation\n")
            actions_c.write("    return BENCH_FAILED;\n")
            actions_c.write("}\n\n")

            actions_c.write(f"struct {struct_name} {struct_name}_init(distro_type_t os)\n")
            actions_c.write("{\n")
            actions_c.write(f"    struct {struct_name} result;\n\n")
            actions_c.write(f"    switch(os)\n")
            actions_c.write("    {\n")
            actions_c.write("        case UBUNTU_22_04:\n")
            actions_c.write(f"            result.audit = {struct_name}_audit;\n")
            actions_c.write(f"            result.remediate = {struct_name}_remediate;\n")
            actions_c.write("            break;\n")
            actions_c.write("        case RHEL_9:\n")
            actions_c.write(f"            result.audit = {struct_name}_audit;\n")
            actions_c.write(f"            result.remediate = {struct_name}_remediate;\n")
            actions_c.write("            break;\n")
            actions_c.write("    }\n")
            actions_c.write("\n    return result;\n")
            actions_c.write("}\n\n")

            actions_c.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name})\n")
            actions_c.write("{\n")
            actions_c.write(f"        (void)({struct_name});\n")
            actions_c.write("}\n\n")

        for struct_name in parent_structures:
            if struct_name == 'bench':
                continue
            actions_c.write(f"struct {struct_name} {struct_name}_init(distro_type_t os)\n")
            actions_c.write("{\n")
            actions_c.write(f"    struct {struct_name} result;\n\n")
            for child in parent_structures[struct_name]:
                rule = child.replace(f"{struct_name}_", "")
                if rule[0].isdigit():
                    rule = f"r{rule}"
                actions_c.write(f"    result.{rule} = {child}_init(os);\n")
            actions_c.write(f"\n    return result;\n")
            actions_c.write("}\n\n")

            actions_c.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name})\n")
            actions_c.write("{\n")
            for child in parent_structures[struct_name]:
                rule = child.replace(f"{struct_name}_", "")
                if rule[0].isdigit():
                    rule = f"r{rule}"
                actions_c.write(f"    {child}_shutdown(&{struct_name}->{rule});\n")
            actions_c.write("}\n\n")

    # Generate a common header file
    with open(os.path.join(output_directory, "benchmarks_common.h"), 'w') as common_h:
        common_h.write(f"#ifndef BENCHMARKS_COMMON_H\n")
        common_h.write(f"#define BENCHMARKS_COMMON_H\n\n")

        common_h.write("typedef enum\n")
        common_h.write("{\n")
        common_h.write("    BENCH_COMPLIANT,\n")
        common_h.write("    BENCH_NON_COMPLIANT,\n")
        common_h.write("    BENCH_FAILED,\n")
        common_h.write("    BENCH_NOT_APPLICABLE\n")
        common_h.write("} action_result_t;\n\n")
        common_h.write("typedef action_result_t (*bench_action_t)();\n\n")

        common_h.write("typedef enum\n")
        common_h.write("{\n")
        common_h.write("\n    // Ubuntu\n")
        common_h.write("    UBUNTU_22_04,\n")
        common_h.write("\n    // Red Hat Enterprise Linux\n")
        common_h.write("    RHEL_9,\n")
        common_h.write("} distro_type_t;\n\n")

        common_h.write(f"#endif // BENCHMARKS_COMMON_H\n\n")

    # Generate a top header file
    with open(os.path.join(output_directory, "benchmarks.h"), 'w') as bench_h:
        bench_h.write(f"#ifndef BENCHMARKS_H\n")
        bench_h.write(f"#define BENCHMARKS_H\n\n")

        bench_h.write("#include \"cis/cis.h\"\n\n")

        bench_h.write("struct benchmarks\n")
        bench_h.write("{\n")
        bench_h.write("    struct bench_cis cis;\n")
        bench_h.write("};\n\n")

        bench_h.write("struct benchmarks benchmarks_init(distro_type_t os);\n")
        bench_h.write("void benchmarks_shutdown(struct benchmarks* benchmarks);\n\n")

        bench_h.write(f"#endif // BENCHMARKS_H\n\n")

    # Generate a top implementation file
    with open(os.path.join(output_directory, "benchmarks.c"), 'w') as bench_h:
        bench_h.write("#include \"benchmarks.h\"\n\n")

        bench_h.write("struct benchmarks benchmarks_init(distro_type_t os)\n")
        bench_h.write("{\n")
        bench_h.write("    struct benchmarks benchmarks;\n\n")
        bench_h.write("    benchmarks.cis = bench_cis_init(os);\n")
        bench_h.write("\n    return benchmarks;\n")
        bench_h.write("}\n\n")

        bench_h.write("void benchmarks_shutdown(struct benchmarks* benchmarks)\n")
        bench_h.write("{\n")
        bench_h.write("    bench_cis_shutdown(&benchmarks->cis);\n")
        bench_h.write("}\n\n")

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

    os.makedirs(os.path.join(output_directory, 'actions'), exist_ok=True)

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
    openapi_file_path = os.path.join(output_directory, 'openapi.yaml')
    with open(openapi_file_path, 'w') as f:
        yaml.dump(asdict(api), f)

    mof_file_path = os.path.join(output_directory, f"{input_definition.benchmark_name}.mof")
    with open(mof_file_path, 'w') as mof_file:
        for path in api.paths:
            if 'get' not in api.paths[path] or 'post' not in api.paths[path]:
                continue
            get = api.paths[path]['get']
            post = api.paths[path]['post']
            mof_file.write("instance of OsConfigResource {\n")
            mof_file.write(f'    ResourceID = "{get.summary}";\n')
            mof_file.write(f'    PayloadKey = "{path}";\n')
            mof_file.write(f'    ComponentName = "CIS_for_Linux";\n')
            mof_file.write(f'    InitObjectName = "/init{path}";\n')
            mof_file.write(f'    ReportedObjectName = "/audit{path}";\n')
            mof_file.write(f'    ExpectedObjectValue = "PASS";\n')
            mof_file.write(f'    DesiredObjectName = "/remediate{path}";\n')
            mof_file.write(f'    DesiredObjectValue = "";\n')
            mof_file.write(f'    ModuleName = "GuestConfiguration";\n')
            mof_file.write(f'    ModuleVersion = "1.0.0";\n')
            mof_file.write(f'    ConfigurationName = "CIS_for_Linux";\n')
            mof_file.write(f'    SourceInfo = "::4::5::OsConfigResource";\n')
            mof_file.write("};\n\n")

    generate_c()