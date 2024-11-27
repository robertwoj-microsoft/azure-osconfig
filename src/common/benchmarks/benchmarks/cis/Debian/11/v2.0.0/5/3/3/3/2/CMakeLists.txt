cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Debian_11_v2_0_0_5_3_3_3_2 STATIC Debian_11_v2.0.0_5_3_3_3_2.c)

target_link_libraries(benchmarks_cis_Debian_11_v2_0_0_5_3_3_3_2 PUBLIC
    logging
    commonutils
)
