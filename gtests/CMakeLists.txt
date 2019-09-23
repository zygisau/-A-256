# 'gtests' is the subproject name
project(gtests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp...' are source files with tests
add_executable(Google_Tests_run main.cpp HashTests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)