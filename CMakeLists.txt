cmake_minimum_required (VERSION 3.5)

if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    set(CMAKE_CXX_COMPILER "icx-cl")
    set(CMAKE_CXX_FLAGS "fsycl")

else()
    set(CMAKE_CXX_COMPILER "/opt/intel/oneapi/2025.1/bin/icpx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsycl")
endif()

project (CONSULTUM LANGUAGES CXX)
add_subdirectory (design/src)
