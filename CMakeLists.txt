cmake_minimum_required(VERSION 3.10)
project(md_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra")

#
find_package(MPI REQUIRED)
find_package(OpenMP REQUIRED)

#
include_directories(${MPI_INCLUDE_PATH})
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

#
set(SOURCES
    src/main.cpp
)

#
add_executable(md_simulator ${SOURCES})

#
target_link_libraries(md_simulator PRIVATE MPI::MPI_CXX OpenMP::OpenMP_CXX)