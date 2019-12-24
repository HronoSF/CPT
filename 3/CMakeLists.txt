cmake_minimum_required(VERSION 3.15)

project(3)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(
        ../include
        ${GTEST_INCLUDE_DIRS}
)

add_executable(3 src/myproject/MyMessage.h src/myproject/MyTie.h src/myproject/MyCat.h src/test/MyCatTest.cpp src/test/MyTieTest.cpp src/test/MyMessageTest.cpp src/myproject/MyCat1.h)

target_link_libraries(3 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()
add_test(MyMessageTest src/test/MyMessageTest.cpp)
add_test(MyCatTest src/test/MyCatTest.cpp)
add_test(MyTieTest src/test/MyTieTest.cpp)