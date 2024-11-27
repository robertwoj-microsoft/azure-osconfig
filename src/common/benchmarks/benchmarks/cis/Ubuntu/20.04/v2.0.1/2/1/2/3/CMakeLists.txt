cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Ubuntu_20_04_v2_0_1_2_1_2_3 STATIC Ubuntu_20.04_v2.0.1_2_1_2_3.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04_v2_0_1_2_1_2_3 PUBLIC
    logging
    commonutils
)
