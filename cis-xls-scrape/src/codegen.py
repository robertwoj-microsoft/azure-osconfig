from dataclasses import dataclass
import os
import struct

@dataclass
class Route:
    path: list[str]
    is_leaf: bool

def create_tree(paths: list[str]) -> dict:
    tree = {}
    for path in paths:
        parts = path.strip('/').split('/')
        current_level = tree
        for part in parts:
            if part not in current_level:
                current_level[part] = {}
            current_level = current_level[part]
    return tree

def post_order_traversal(tree: dict) -> list[Route]:
    def traversal(tree, node, path, routes: list[Route]):
        if node not in tree:
            return
        subtree = tree[node]
        for key in subtree:
            path.append(node)
            traversal(subtree, key, path, routes)
            path.pop()
        routes.append(Route(path + [node], not tree[node]))

    routes = list[Route]()
    traversal(tree, 'benchmarks', [], routes)
    return routes

def make_directories(output_directory: str, path: list[str]):
    path = os.path.join(output_directory, *path)
    os.makedirs(path, exist_ok=True)

def make_stem(path: list[str]) -> str:
    if len(path) > 2:
        return "_".join(path[2:])
    else:
        return path[-1]

def make_relative_path(path: list[str], extension: str) -> str:
    return os.path.join(*path, make_stem(path)) + f".{extension}"

def make_filename(output_directory: str, path: list[str], extension: str) -> str:
    return os.path.join(output_directory, *path, make_stem(path)) + f".{extension}"

def make_structure_name(route: Route, child: str = None) -> str:
    if child:
        return "_".join(route.path + [child]).replace('.', '_')
    return "_".join(route.path).replace('.', '_')

def get_route_children(tree: dict, route: Route) -> list[str]:
    node = tree
    for part in route.path:
        node = node[part]
    return list(node.keys())

def make_cmake_lists_file(output_directory: str, tree: dict, route: Route):
    path = os.path.join(output_directory, *route.path)
    # print(f"Generating CMakeLists.txt for {path}")

    with open(os.path.join(path, "CMakeLists.txt"), 'w') as cmake_lists:
        cmake_lists.write("cmake_minimum_required(VERSION 3.2)\n\n")
        structure_name = make_structure_name(route)
        if route.is_leaf:
            cmake_lists.write("if(BUILD_TESTS)\n")
            cmake_lists.write(f"    add_subdirectory(test)\n")
            cmake_lists.write("endif()\n\n")
            cmake_lists.write(f"add_library({structure_name} STATIC {make_stem(route.path)}.c)\n")
            cmake_lists.write(f"\ntarget_link_libraries({structure_name} PUBLIC\n")
            cmake_lists.write(f"    logging\n")
            cmake_lists.write(f"    commonutils\n")
            cmake_lists.write(")\n")
        else:
            children = get_route_children(tree, route)
            for child in children:
                cmake_lists.write(f"add_subdirectory({child})\n")
            cmake_lists.write(f"\nadd_library({structure_name} STATIC {make_stem(route.path)}.c)\n")
            cmake_lists.write(f"\ntarget_link_libraries({structure_name} PUBLIC\n")
            cmake_lists.write(f"    logging\n")
            for child in children:
                sub_structure_name = make_structure_name(route, child)
                cmake_lists.write(f"    {sub_structure_name}\n")
            cmake_lists.write(")\n")

def make_header_file(output_directory: str, tree: dict, route: Route):
    filename = make_filename(output_directory, route.path, 'h')
    header_guard = ("_".join(route.path).replace('.', '_') + "_H").upper()
    structure_name = make_structure_name(route)
    children = get_route_children(tree, route)

    # print(f"Generating header file: {filename}")
    with open(filename, 'w') as header_file:
        header_file.write(f"#ifndef {header_guard}\n")
        header_file.write(f"#define {header_guard}\n\n")
        header_file.write("#ifdef __cplusplus\n")
        header_file.write("extern \"C\" {\n")
        header_file.write("#endif\n\n")
        relative_common_header = "../" * (len(route.path) - 1) + "benchmarks_common.h"
        header_file.write(f"#include \"{relative_common_header}\"\n\n")

        if route.is_leaf:
            header_file.write(f"struct {structure_name}\n")
            header_file.write("{\n")
            header_file.write("    bench_action_t audit;\n")
            header_file.write("    bench_action_t remediate;\n")
            header_file.write("};\n\n")
        else:
            for child in children:
                header_file.write(f"#include \"{child}/{make_stem(route.path + [child])}.h\"\n")

            header_file.write(f"\nstruct {structure_name}\n")
            header_file.write("{\n")
            for child in children:
                sub_structure_name = make_structure_name(route, child)
                header_file.write(f"    struct {sub_structure_name} rule_{child.replace('.', '_')};\n")
            header_file.write("};\n\n")

        header_file.write(f"struct {structure_name} {structure_name}_init();\n")
        # header_file.write(f"void {structure_name}_shutdown(struct {structure_name}* {structure_name});\n\n")
        header_file.write(f"benchmark_result_t {structure_name}_audit(const struct {structure_name}* interface, const char* path, void* log);\n")
        header_file.write(f"benchmark_result_t {structure_name}_remediate(const struct {structure_name}* interface, const char* path, void* log);\n")

        header_file.write("#ifdef __cplusplus\n")
        header_file.write("}\n")
        header_file.write("#endif\n\n")
        header_file.write(f"#endif // {header_guard}\n\n")

def make_implementation_file(output_directory: str, tree: dict, route: Route):
    filename = make_filename(output_directory, route.path, 'c')
    structure_name = make_structure_name(route)
    children = get_route_children(tree, route)

    # print(f"Generating implementation file: {filename}")
    with open(filename, 'w') as implementation_file:
        implementation_file.write(f"#include \"{make_stem(route.path)}.h\"\n")
        implementation_file.write(f"#include \"CommonUtils.h\"\n\n")

        if route.is_leaf:
            implementation_file.write(f"static benchmark_result_t audit(void* log)\n")
            implementation_file.write("{\n")
            implementation_file.write("    int status = -1;\n")
            implementation_file.write("    char* result = NULL;\n\n")
            implementation_file.write(f"    OsConfigLogInfo(log, \"[CIS] Audit for {structure_name}\");\n")
            implementation_file.write("    status = ExecuteCommand(NULL, \"/bin/bash /tmp/audit.sh\", false, false, 1024 * 1024, 10, &result, NULL, log);\n")
            implementation_file.write("    if (0 != status || NULL == result)\n")
            implementation_file.write("    {\n")
            implementation_file.write("        OsConfigLogError(log, \"Failed to execute audit.sh\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n\n")
            implementation_file.write("    OsConfigLogInfo(log, \"Audit result: %s\", result);\n")
            implementation_file.write("    return BENCHMARK_COMPLIANT;\n")
            implementation_file.write("}\n\n")

            implementation_file.write(f"static benchmark_result_t remediate(void *log)\n")
            implementation_file.write("{\n")
            implementation_file.write("    // TODO: Implement remediation\n")
            implementation_file.write(f"    OsConfigLogInfo(log, \"[CIS] Remediation for {structure_name}\");\n")
            implementation_file.write("    return BENCHMARK_FAILED;\n")
            implementation_file.write("}\n\n")

            implementation_file.write(f"struct {structure_name} {structure_name}_init()\n")
            implementation_file.write("{\n")
            implementation_file.write(f"    struct {structure_name} interface;\n\n")
            implementation_file.write(f"    interface.audit = audit;\n")
            implementation_file.write(f"    interface.remediate = remediate;\n")
            implementation_file.write("\n    return interface;\n")
            implementation_file.write("}\n\n")

            implementation_file.write(f"benchmark_result_t {structure_name}_audit(const struct {structure_name}* interface, const char* path, void* log)\n")
            implementation_file.write("{\n")
            implementation_file.write(f"    if (NULL == interface || NULL == path)\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_audit: NULL argument\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n")
            implementation_file.write("\n")
            implementation_file.write(f"    if (0 != strcmp(path, \"/audit\"))\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_audit: Invalid path\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n\n")
            implementation_file.write(f"    return interface->audit(log);\n")
            implementation_file.write("}\n\n")

            implementation_file.write(f"benchmark_result_t {structure_name}_remediate(const struct {structure_name}* interface, const char* path, void* log)\n")
            implementation_file.write("{\n")
            implementation_file.write(f"    if (NULL == interface || NULL == path)\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_remediate: NULL argument\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n")
            implementation_file.write("\n")
            implementation_file.write(f"    if (0 != strcmp(path, \"/remediate\"))\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_remediate: Invalid path\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n\n")
            implementation_file.write(f"    return interface->remediate(log);\n")
            implementation_file.write("}\n\n")
        else:
            implementation_file.write(f"benchmark_result_t {structure_name}_audit(const struct {structure_name}* interface, const char* path, void* log)\n")
            implementation_file.write("{\n")
            implementation_file.write(f"    if (NULL == interface || NULL == path)\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_audit: NULL argument\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n")
            implementation_file.write("\n")
            implementation_file.write("    if ('/' != path[0])\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_audit: Invalid path\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n\n")
            for child in children:
                sub_structure_name = make_structure_name(route, child)
                implementation_file.write(f"    if (0 == strncmp(path + 1, \"{child}\", strlen(\"{child}\")))\n")
                implementation_file.write("    {\n")
                implementation_file.write(f"        return {sub_structure_name}_audit(&interface->rule_{child.replace('.', '_')}, path + strlen(\"{child}\") + 1, log);\n")
                implementation_file.write("    }\n\n")
            implementation_file.write(f"    OsConfigLogError(log, \"{structure_name}_audit: Unrecognized path: %s\", path);\n")
            implementation_file.write("    return BENCHMARK_FAILED;\n")
            implementation_file.write("}\n\n")

            implementation_file.write(f"benchmark_result_t {structure_name}_remediate(const struct {structure_name}* interface, const char* path, void* log)\n")
            implementation_file.write("{\n")
            implementation_file.write(f"    if (NULL == interface || NULL == path)\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_remediate: NULL argument\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n")
            implementation_file.write("\n")
            implementation_file.write("    if ('/' != path[0])\n")
            implementation_file.write("    {\n")
            implementation_file.write(f"        OsConfigLogError(log, \"{structure_name}_remediate: Invalid path\");\n")
            implementation_file.write("        return BENCHMARK_FAILED;\n")
            implementation_file.write("    }\n\n")
            for child in children:
                sub_structure_name = make_structure_name(route, child)
                implementation_file.write(f"    if (0 == strncmp(path + 1, \"{child}\", strlen(\"{child}\")))\n")
                implementation_file.write("    {\n")
                implementation_file.write(f"        return {sub_structure_name}_remediate(&interface->rule_{child.replace('.', '_')}, path + strlen(\"{child}\") + 1, log);\n")
                implementation_file.write("    }\n\n")
            implementation_file.write(f"    OsConfigLogError(log, \"{structure_name}_audit: Unrecognized path: %s\", path);\n")
            implementation_file.write("    return BENCHMARK_FAILED;\n")
            implementation_file.write("}\n\n")

            implementation_file.write(f"struct {structure_name} {structure_name}_init()\n")
            implementation_file.write("{\n")
            implementation_file.write(f"    struct {structure_name} result;\n\n")
            for child in children:
                sub_structure_name = make_structure_name(route, child)
                implementation_file.write(f"    result.rule_{child.replace('.', '_')} = {sub_structure_name}_init();\n")
            implementation_file.write(f"\n    return result;\n")
            implementation_file.write("}\n\n")

            # implementation_file.write(f"void {structure_name}_shutdown(struct {structure_name}* {structure_name})\n")
            # implementation_file.write("{\n")
            # for child in children:
            #     sub_structure_name = make_structure_name(route, child)
            #     implementation_file.write(f"    {sub_structure_name}_shutdown(&{structure_name}->rule_{child.replace('.', '_')});\n")
            # implementation_file.write("}\n\n")

def make_test_case(output_directory: str, route: Route):
    if not route.is_leaf:
        return

    make_directories(output_directory, route.path + ['test'])
    filename = make_filename(output_directory, route.path + ['test'], 'cpp')

    with open(filename, 'w') as test_file:
        test_file.write("#include <gtest/gtest.h>\n\n")
        test_file.write(f"#include \"../{make_stem(route.path)}.h\"\n\n")
        test_file.write("int main(int argc, char** argv) {\n")
        test_file.write("    ::testing::InitGoogleTest(&argc, argv);\n")
        test_file.write("    return RUN_ALL_TESTS();\n")
        test_file.write("}\n")

    # Create a CMakeLists.txt file for the test directory
    with open(os.path.join(output_directory, *route.path, 'test', 'CMakeLists.txt'), 'w') as cmake_lists:
        structure_name = make_structure_name(route)
        test_name = make_stem(route.path).replace('.', '_') + "_test"
        cmake_lists.write("cmake_minimum_required(VERSION 3.2)\n\n")
        cmake_lists.write("find_package(GTest REQUIRED)\n\n")
        cmake_lists.write(f"add_executable(test_{structure_name} {make_stem(route.path)}_test.cpp)\n")
        cmake_lists.write(f"target_link_libraries(test_{structure_name} PRIVATE GTest::GTest GTest::Main {structure_name})\n\n")
        cmake_lists.write(f"gtest_discover_tests(test_{structure_name} XML_OUTPUT_DIR ${{GTEST_OUTPUT_DIR}})\n")

def generate_code(paths, output_directory: str, benchmark_name: str):
    leaf_structures = set()
    parent_structures = dict()
    def traverse_tree(tree, path='', depth=0):
        for key, value in tree.items():
            traverse_tree(value, f"{path}_{key.replace('.', '_')}", depth + 1)

            if not value:
                leaf_structures.add(f"{path}_{key.replace('.', '_')}")
            if path not in parent_structures:
                parent_structures[path] = set()
            parent_structures[path].add(f"{path}_{key.replace('.', '_')}")

    # not perfect, but easiest: lexicographically sort the paths
    ordered_paths = sorted(list(paths))
    tree = create_tree(ordered_paths)
    traverse_tree(tree)

    routes = post_order_traversal(tree)
    print(f"Routes: {len(routes)}")
    for route in routes:
        make_directories(output_directory, route.path)
        make_cmake_lists_file(output_directory, tree, route)
        make_header_file(output_directory, tree, route)
        make_implementation_file(output_directory, tree, route)
        make_test_case(output_directory, route)

    # Generate a common header file
    with open(os.path.join(output_directory, "benchmarks", "benchmarks_common.h"), 'w') as common_h:
        common_h.write(f"#ifndef BENCHMARKS_COMMON_H\n")
        common_h.write(f"#define BENCHMARKS_COMMON_H\n\n")
        common_h.write("#ifdef __cplusplus\n")
        common_h.write("extern \"C\" {\n")
        common_h.write("#endif\n\n")

        common_h.write("#include <string.h>\n")
        common_h.write("#include <stdbool.h>\n")
        common_h.write("#include <stdio.h>\n")
        common_h.write("#include <Logging.h>\n\n")

        common_h.write("typedef enum\n")
        common_h.write("{\n")
        common_h.write("    BENCHMARK_COMPLIANT,\n")
        common_h.write("    BENCHMARK_NON_COMPLIANT,\n")
        common_h.write("    BENCHMARK_FAILED,\n")
        common_h.write("    BENCHMARK_NOT_APPLICABLE\n")
        common_h.write("} benchmark_result_t;\n\n")
        common_h.write("typedef benchmark_result_t (*bench_action_t)(void*);\n\n")

        common_h.write("#ifdef __cplusplus\n")
        common_h.write("}\n")
        common_h.write("#endif\n\n")
        common_h.write(f"#endif // BENCHMARKS_COMMON_H\n\n")

    # Generate a top level CMakeLists.txt file
    with open(os.path.join(output_directory, "CMakeLists.txt"), 'w') as top_cmake_lists:
        top_cmake_lists.write("cmake_minimum_required(VERSION 3.2)\n\n")
        top_cmake_lists.write("add_subdirectory(benchmarks)\n")

    # For each node in the tree, we generate a structure and a set of functions to audit and remediate the configuration
    # We must iterate in post-order to ensure that we generate the child nodes are generated before the parent nodes

    # Generate a header file for the actions
    # with open(os.path.join(output_directory, benchmark_name, f"{benchmark_name}.h"), 'w') as actions_h:
    #     # TODO: disclaimer, license, etc.
    #     actions_h.write(f"#ifndef {benchmark_name.upper()}_ACTIONS_H\n")
    #     actions_h.write(f"#define {benchmark_name.upper()}_ACTIONS_H\n\n")

    #     actions_h.write("#include \"../benchmarks_common.h\"\n\n")

    #     for struct_name in leaf_structures:
    #         actions_h.write(f"struct {struct_name}\n")
    #         actions_h.write("{\n")
    #         actions_h.write("    bench_action_t audit;\n")
    #         actions_h.write("    bench_action_t remediate;\n")
    #         actions_h.write("};\n\n")
    #         actions_h.write(f"struct {struct_name} {struct_name}_init(distro_type_t os);\n")
    #         actions_h.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name});\n\n")

    #     visited_nodes = []
    #     # post_order_traversal(parent_structures, 'bench', visited_nodes)
    #     for struct_name in visited_nodes:
    #         if struct_name == 'bench':
    #             continue
    #         actions_h.write(f"struct {struct_name}\n")
    #         actions_h.write("{\n")
    #         for child in parent_structures[struct_name]:
    #             rule = child.replace(f"{struct_name}_", "")
    #             if rule[0].isdigit():
    #                 rule = f"r{rule}"
    #             actions_h.write(f"    struct {child} {rule};\n")
    #         actions_h.write("};\n\n")
    #         actions_h.write(f"struct {struct_name} {struct_name}_init(distro_type_t os);\n")
    #         actions_h.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name});\n\n")

    #     actions_h.write(f"#endif // {benchmark_name.upper()}_ACTIONS_H\n\n")

    # # Generate a source file for the actions
    # with open(os.path.join(output_directory, benchmark_name, f"{benchmark_name}.c"), 'w') as actions_c:
    #     actions_c.write(f"#include \"{benchmark_name}.h\"\n")
    #     actions_c.write("#include <string.h>\n")
    #     actions_c.write("#include <stdbool.h>\n")
    #     actions_c.write("#include <stdio.h>\n")
    #     actions_c.write("#include <Logging.h>\n\n")

    #     for struct_name in leaf_structures:
    #         actions_c.write(f"static benchmark_result_t {struct_name}_audit()\n")
    #         actions_c.write("{\n")
    #         actions_c.write("    // TODO: Implement audit\n")
    #         actions_c.write(f"    OsConfigLogInfo(NULL, \"[CIS] Audit for {struct_name}\");\n")
    #         actions_c.write("    return BENCHMARK_FAILED;\n")
    #         actions_c.write("}\n\n")

    #         actions_c.write(f"static benchmark_result_t {struct_name}_remediate()\n")
    #         actions_c.write("{\n")
    #         actions_c.write("    // TODO: Implement remediation\n")
    #         actions_c.write(f"    OsConfigLogInfo(NULL, \"[CIS] Remediation for {struct_name}\");\n")
    #         actions_c.write("    return BENCHMARK_FAILED;\n")
    #         actions_c.write("}\n\n")

    #         actions_c.write(f"struct {struct_name} {struct_name}_init(distro_type_t os)\n")
    #         actions_c.write("{\n")
    #         actions_c.write(f"    struct {struct_name} result;\n\n")
    #         actions_c.write(f"    switch(os)\n")
    #         actions_c.write("    {\n")
    #         actions_c.write("        case UBUNTU_22_04:\n")
    #         actions_c.write(f"            result.audit = {struct_name}_audit;\n")
    #         actions_c.write(f"            result.remediate = {struct_name}_remediate;\n")
    #         actions_c.write("            break;\n")
    #         actions_c.write("        case RHEL_9:\n")
    #         actions_c.write(f"            result.audit = {struct_name}_audit;\n")
    #         actions_c.write(f"            result.remediate = {struct_name}_remediate;\n")
    #         actions_c.write("            break;\n")
    #         actions_c.write("    }\n")
    #         actions_c.write("\n    return result;\n")
    #         actions_c.write("}\n\n")

    #         actions_c.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name})\n")
    #         actions_c.write("{\n")
    #         actions_c.write(f"    (void)({struct_name});\n")
    #         actions_c.write("}\n\n")

    #     for struct_name in parent_structures:
    #         if struct_name == 'bench':
    #             continue
    #         actions_c.write(f"struct {struct_name} {struct_name}_init(distro_type_t os)\n")
    #         actions_c.write("{\n")
    #         actions_c.write(f"    struct {struct_name} result;\n\n")
    #         for child in parent_structures[struct_name]:
    #             rule = child.replace(f"{struct_name}_", "")
    #             if rule[0].isdigit():
    #                 rule = f"r{rule}"
    #             actions_c.write(f"    result.{rule} = {child}_init(os);\n")
    #         actions_c.write(f"\n    return result;\n")
    #         actions_c.write("}\n\n")

    #         actions_c.write(f"void {struct_name}_shutdown(struct {struct_name}* {struct_name})\n")
    #         actions_c.write("{\n")
    #         for child in parent_structures[struct_name]:
    #             rule = child.replace(f"{struct_name}_", "")
    #             if rule[0].isdigit():
    #                 rule = f"r{rule}"
    #             actions_c.write(f"    {child}_shutdown(&{struct_name}->{rule});\n")
    #         actions_c.write("}\n\n")

    # # Generate a common header file
    # with open(os.path.join(output_directory, "benchmarks_common.h"), 'w') as common_h:
    #     common_h.write(f"#ifndef BENCHMARKS_COMMON_H\n")
    #     common_h.write(f"#define BENCHMARKS_COMMON_H\n\n")

    #     common_h.write("#include <string.h>\n")
    #     common_h.write("#include <stdbool.h>\n")
    #     common_h.write("#include <stdio.h>\n")
    #     common_h.write("#include <Logging.h>\n\n")

    #     common_h.write("typedef enum\n")
    #     common_h.write("{\n")
    #     common_h.write("    BENCHMARK_COMPLIANT,\n")
    #     common_h.write("    BENCHMARK_NON_COMPLIANT,\n")
    #     common_h.write("    BENCHMARK_FAILED,\n")
    #     common_h.write("    BENCHMARK_NOT_APPLICABLE\n")
    #     common_h.write("} benchmark_result_t;\n\n")
    #     common_h.write("typedef benchmark_result_t (*bench_action_t)();\n\n")

    #     common_h.write("typedef enum\n")
    #     common_h.write("{\n")
    #     common_h.write("\n    // Ubuntu\n")
    #     common_h.write("    UBUNTU_22_04,\n")
    #     common_h.write("\n    // Red Hat Enterprise Linux\n")
    #     common_h.write("    RHEL_9,\n")
    #     common_h.write("} distro_type_t;\n\n")

    #     common_h.write(f"#endif // BENCHMARKS_COMMON_H\n\n")

    # # Generate a top header file
    # with open(os.path.join(output_directory, "benchmarks.h"), 'w') as bench_h:
    #     bench_h.write(f"#ifndef BENCHMARKS_H\n")
    #     bench_h.write(f"#define BENCHMARKS_H\n\n")

    #     bench_h.write("#include \"cis/cis.h\"\n\n")

    #     bench_h.write("struct benchmarks\n")
    #     bench_h.write("{\n")
    #     bench_h.write("    struct bench_cis cis;\n")
    #     bench_h.write("};\n\n")

    #     bench_h.write("struct benchmarks benchmarks_init(distro_type_t os);\n")
    #     bench_h.write("void benchmarks_shutdown(struct benchmarks* benchmarks);\n")
    #     bench_h.write("benchmark_result_t benchmarks_audit(const struct benchmarks* bench, const char* path, void* log);\n\n")
    #     bench_h.write(f"#endif // BENCHMARKS_H\n\n")

    # # Generate a top implementation file
    # with open(os.path.join(output_directory, "benchmarks.c"), 'w') as bench_h:
    #     bench_h.write("#include \"benchmarks.h\"\n\n")
    #     bench_h.write("#include \"benchmarks_common.h\"\n\n")

    #     bench_h.write("struct benchmarks benchmarks_init(distro_type_t os)\n")
    #     bench_h.write("{\n")
    #     bench_h.write("    struct benchmarks benchmarks;\n\n")
    #     bench_h.write("    benchmarks.cis = bench_cis_init(os);\n")
    #     bench_h.write("\n    return benchmarks;\n")
    #     bench_h.write("}\n\n")

    #     bench_h.write("void benchmarks_shutdown(struct benchmarks* benchmarks)\n")
    #     bench_h.write("{\n")
    #     bench_h.write("    bench_cis_shutdown(&benchmarks->cis);\n")
    #     bench_h.write("}\n\n")

    #     bench_h.write("benchmark_result_t benchmarks_audit(const struct benchmarks* bench, const char* path, void* log)\n")
    #     bench_h.write("{\n")
    #     bench_h.write("    if (NULL == bench || NULL == path)\n")
    #     bench_h.write("    {\n")
    #     bench_h.write("        OsConfigLogError(log, \"benchmarks_audit: Invalid argument\");\n")
    #     bench_h.write("        return BENCHMARK_FAILED;\n")
    #     bench_h.write("    }\n")
    #     bench_h.write("\n")
    #     bench_h.write("    if ('/' != path[0])\n")
    #     bench_h.write("    {\n")
    #     bench_h.write("        OsConfigLogError(log, \"benchmarks_audit: Invalid path\");\n")
    #     bench_h.write("        return BENCHMARK_FAILED;\n")
    #     bench_h.write("    }\n")
    #     bench_h.write("\n")
    #     bench_h.write("    if (0 == strncmp(path, \"/cis\", strlen(\"/cis\")))\n")
    #     bench_h.write("    {\n")
    #     bench_h.write("        return bench_cis_audit(&bench->cis, path + strlen(\"/cis\"));\n")
    #     bench_h.write("    }\n")
    #     bench_h.write("    else\n")
    #     bench_h.write("    {\n")
    #     bench_h.write("        OsConfigLogError(log, \"benchmarks_audit: Unrecognized path: %s\", path);\n")
    #     bench_h.write("        return BENCHMARK_FAILED;\n")
    #     bench_h.write("    }\n")
    #     bench_h.write("}\n\n")
