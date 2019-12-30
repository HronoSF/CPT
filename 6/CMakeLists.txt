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

add_executable(4 src/myproject/GeometryFigures.h
        src/myproject/Polynomial.h
        src/test/GeometryFiguresTest.cc
        src/test/PolynomialTest.cc)

target_link_libraries(4 ${GTEST_BOTH_LIBRARIES}  Threads::Threads)

enable_testing()
add_test(PolynomialTest /src/test/PolynomialTest.cc)
add_test(GeometryFiguresTest /src/test/GeometryFiguresTest.cc)



