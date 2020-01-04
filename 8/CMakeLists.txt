cmake_minimum_required(VERSION 3.15)

project(8)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(
        ../include
        ${GTEST_INCLUDE_DIRS}
)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11 -I/usr/include/python2.7 -lpython2.7")

add_executable(8 src/myproject/MergeSort.h src/myproject/main.cpp src/myproject/resources/matplotlibcpp.h ${SOURCE_FILES} src/test/MergeSortTest.cpp
        src/myproject/resources/MergeSort.h)

target_link_libraries(8 ${PYTHON_LIBRARIES})

target_link_libraries(8 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()
add_test(MergeSrotTest src/test/MergeSortTest.cpp)