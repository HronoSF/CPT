cmake_minimum_required(VERSION 3.15)

project(10)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(
        ../include
        ${GTEST_INCLUDE_DIRS}
)


add_executable(10 src/myproject/TurnOn.h src/test/TurnOnTest.cpp)

target_link_libraries(10 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()