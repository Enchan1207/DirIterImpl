#
# iterdir sources
#

cmake_minimum_required(VERSION 3.0)

## add external dependencies here

## configure executable
add_executable(main)
target_sources(main PRIVATE
    main.cpp
)
target_include_directories(main PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_compile_options(main PRIVATE
    -Wall
)
target_link_libraries(main PRIVATE
    iterdir
)

## configure library
add_library(iterdir)
target_sources(iterdir PRIVATE
    iterdir.cpp
)
target_include_directories(iterdir PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_compile_options(iterdir PRIVATE
    -Wall
)
