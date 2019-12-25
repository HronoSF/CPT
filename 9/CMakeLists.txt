cmake_minimum_required(VERSION 3.15)

project(9)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(9
        src/myproject/3/MyCat.h
        src/myproject/3/MyMessage.h
        src/myproject/3/MyTie.h

        src/myproject/4/main.cpp
        src/myproject/4/Guard.h
        src/myproject/4/MyMatrix.h
        src/myproject/4/MyMatrix.hxx

        src/myproject/5/main.cpp
        src/myproject/5/MergeSort.h
        src/myproject/5/MyIterator.h
        src/myproject/5/PersonAccount.h

        src/myproject/7/main.cpp
        src/myproject/7/ln80c_buffer.h
        src/myproject/7/startBuffer.h

        src/myproject/8/main.cpp
        src/myproject/8/MergeSort.h

        src/test/3/MyCatTest.cpp
        src/test/3/MyMessageTest.cpp
        src/test/3/MyTieTest.cpp

        src/test/4/GuardTest.cpp
        src/test/4/MyMatrixTestIsSymmetricMethodDataProvider.cpp
        src/test/4/MyMatrixTestWhereMethodDataProvider.cpp

        src/test/5/MergeSortTest.cpp
        src/test/5/PersonAccountTest.cpp
        src/test/5/MyIteratorTest.cpp

        src/test/7/ln80cBufferTest.cpp

        src/test/8/MergeSortTest.cpp
        )

target_link_libraries(9 ${GTEST_BOTH_LIBRARIES} Threads::Threads)

enable_testing()
add_test(MyMessageTest src/test/3/MyMessageTest.cpp)
add_test(MyCatTest src/test/3/MyCatTest.cpp)
add_test(MyTieTest src/test/3/MyTieTest.cpp)
add_test(MyMatrixTestWithDataProvider src/test/4/MyMatrixTestWhereMethodDataProvider.cpp)
add_test(MyMatrixTestIsSymmetricMethodDataProvider src/test/4/MyMatrixTestIsSymmetricMethodDataProvider.cpp)
add_test(GuardTest src/test/4/GuardTest.cpp)
add_test(MergeSortTest src/test/5/MergeSortTest.cpp)
add_test(MyIteratorTest src/test/5/MyIteratorTest.cpp)
add_test(PersonAccountTest src/test/5/PersonAccountTest.cpp)
add_test(ln80cBufferTest src/test/7/ln80cBufferTest.cpp)
add_test(MergeSrotTest src/test/8/MergeSortTest.cpp)