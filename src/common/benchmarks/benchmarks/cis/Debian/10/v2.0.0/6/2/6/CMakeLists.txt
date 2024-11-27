cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Debian_10_v2_0_0_6_2_6 STATIC Debian_10_v2.0.0_6_2_6.c)

target_link_libraries(benchmarks_cis_Debian_10_v2_0_0_6_2_6 PUBLIC
    logging
    commonutils
)
