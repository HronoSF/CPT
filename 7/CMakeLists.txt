cmake_minimum_required(VERSION 3.15)

project(7)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(
        ../include
        ${GTEST_INCLUDE_DIRS}
)

add_executable(7 src/myproject/ln80c_buffer.h src/myproject/startBuffer.h src/myproject/main.cpp src/test/ln80cBufferTest.cpp)

target_link_libraries(7 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()

add_test(ln80cBufferTest src/test/ln80cBufferTest.cpp)