cmake_minimum_required(VERSION 3.15)
project(11)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(
        ../include
        ${GTEST_INCLUDE_DIRS}
)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include/python2.7 -lpython2.7")

add_executable(11 src/myproject/MyThread.hxx src/test/MyThreadTest.cpp)

target_link_libraries(11 ${PYTHON_LIBRARIES})

target_link_libraries(11 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()
add_test(MyThreadTest src/test/MyThreadTest.cpp)