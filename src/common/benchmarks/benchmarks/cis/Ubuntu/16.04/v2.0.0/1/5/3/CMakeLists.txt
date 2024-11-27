cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_5_3 STATIC Ubuntu_16.04_v2.0.0_1_5_3.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_5_3 PUBLIC
    logging
    commonutils
)
