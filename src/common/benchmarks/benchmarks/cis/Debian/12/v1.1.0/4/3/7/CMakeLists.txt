cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Debian_12_v1_1_0_4_3_7 STATIC Debian_12_v1.1.0_4_3_7.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0_4_3_7 PUBLIC
    logging
    commonutils
)
