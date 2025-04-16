# Incluye los headers de TBB
include_directories($ENV{TBBROOT}/include)

# Set default build type to RelWithDebInfo if not specified
if (NOT CMAKE_BUILD_TYPE)
    message (STATUS "Default CMAKE_BUILD_TYPE not set. Using Release with Debug Info")
    set (CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE
        STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel"
        FORCE)
endif()
add_executable(CONSULTUM main.cpp)
target_link_libraries(CONSULTUM PRIVATE $ENV{TBBROOT}/lib/intel64/gcc4.8/libtbb.so)

add_custom_target (run ./CONSULTUM)
