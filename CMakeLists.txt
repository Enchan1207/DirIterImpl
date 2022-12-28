#
# DirIterImpl
#
cmake_minimum_required(VERSION 3.0)
project(DirIterImpl
    VERSION 0.1.0
    DESCRIPTION "Implementation check of std::directory_iterator"
    LANGUAGES C CXX
)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(/MTd)
    else()
        add_compile_options(/MT)
    endif()
endif()

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
