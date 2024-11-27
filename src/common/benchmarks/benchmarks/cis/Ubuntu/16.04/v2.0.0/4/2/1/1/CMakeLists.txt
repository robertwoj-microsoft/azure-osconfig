cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_4_2_1_1 STATIC Ubuntu_16.04_v2.0.0_4_2_1_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_4_2_1_1 PUBLIC
    logging
    commonutils
)
