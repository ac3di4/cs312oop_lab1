# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
add_executable(task2_tests DeltoidTests.cpp Deltoid.hpp)

# Link test executable against gtest & gtest_main
target_link_libraries(task2_tests gtest gtest_main)
add_test(task2_tests task2_tests)

add_executable(task2 main.cpp)