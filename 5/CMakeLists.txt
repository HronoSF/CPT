cmake_minimum_required(VERSION 3.15)

project(5)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(
        ../include
        ${GTEST_INCLUDE_DIRS}
)

add_executable(5 src/myproject/MyIterator.h src/myproject/MergeSort.h
        src/myproject/main.cpp src/test/MergeSortTest.cpp src/myproject/PersonAcc.h)

target_link_libraries(5 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()
add_test(MergeSortTest src/test/MergeSortTest.cpp)
