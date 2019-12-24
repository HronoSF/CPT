cmake_minimum_required(VERSION 3.15)

project(4)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(
        ../include
        ${GTEST_INCLUDE_DIRS}
)

add_executable(4 src/myproject/Guard.h src/myproject/main.cpp src/myproject/MyMatrix.h src/myproject/MyMatrix.hxx src/test/MyMatrixTestWhereMethodDataProvider.cpp src/test/MyMatrixTestIsSymmetricMethodDataProvider.cpp src/test/GuardTest.cpp)

target_link_libraries(4 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()
add_test(MyMatrixTestWithDataProvider src/test/MyMatrixTestWhereMethodDataProvider.cpp)
add_test(MyMatrixTestIsSymmetricMethodDataProvider src/test/MyMatrixTestIsSymmetricMethodDataProvider.cpp)
add_test(GuardTest src/test/GuardTest.cpp)