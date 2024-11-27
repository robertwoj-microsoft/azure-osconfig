cmake_minimum_required(VERSION 3.2)

add_subdirectory(Alma)
add_subdirectory(Azure)
add_subdirectory(CentOS)
add_subdirectory(Debian)
add_subdirectory(FreeBSD)
add_subdirectory(Oracle)
add_subdirectory(RHEL)
add_subdirectory(Rocky)
add_subdirectory(SUSE)
add_subdirectory(Ubuntu)

add_library(benchmarks_cis STATIC cis.c)

target_link_libraries(benchmarks_cis PUBLIC
    logging
    benchmarks_cis_Alma
    benchmarks_cis_Azure
    benchmarks_cis_CentOS
    benchmarks_cis_Debian
    benchmarks_cis_FreeBSD
    benchmarks_cis_Oracle
    benchmarks_cis_RHEL
    benchmarks_cis_Rocky
    benchmarks_cis_SUSE
    benchmarks_cis_Ubuntu
)
