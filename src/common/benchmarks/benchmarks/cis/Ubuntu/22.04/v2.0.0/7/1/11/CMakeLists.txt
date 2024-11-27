cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Ubuntu_22_04_v2_0_0_7_1_11 STATIC Ubuntu_22.04_v2.0.0_7_1_11.c)

target_link_libraries(benchmarks_cis_Ubuntu_22_04_v2_0_0_7_1_11 PUBLIC
    logging
    commonutils
)
