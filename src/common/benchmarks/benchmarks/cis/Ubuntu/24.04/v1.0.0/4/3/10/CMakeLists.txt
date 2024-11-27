cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Ubuntu_24_04_v1_0_0_4_3_10 STATIC Ubuntu_24.04_v1.0.0_4_3_10.c)

target_link_libraries(benchmarks_cis_Ubuntu_24_04_v1_0_0_4_3_10 PUBLIC
    logging
    commonutils
)
