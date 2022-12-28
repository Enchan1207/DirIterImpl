#
#
#
cmake_minimum_required(VERSION 3.0)

# GoogleTestのフェッチと有効化
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest) # gtest_系関数の読み込み

# テストターゲットの構成
add_executable(iterdir_test)
target_sources(iterdir_test PRIVATE
    test_iterdir.cpp
)
target_link_libraries(iterdir_test PRIVATE
    iterdir
    GTest::gtest_main
)
target_include_directories(iterdir_test PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${GTEST_INCLUDE_DIRS}
)

# テストの実行
gtest_discover_tests(iterdir_test)
