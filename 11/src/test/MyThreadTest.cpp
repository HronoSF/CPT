#include <gtest/gtest.h>
#include <thread>
#include <chrono>
#include "../myproject/MyThread.hxx"

int Inf(void* arg){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}

TEST(MyThread_Test, Test_Joinable){
    my_thread thd(Inf);
    EXPECT_EQ(true, thd.joinable());
}

TEST(MyThread_Test, Test_Join){
    my_thread thd(Inf);

    thd.join();
    EXPECT_EQ(false, thd.joinable());
}

TEST(MyThread_Test, Test_Swap){
    my_thread thd1(Inf);
    my_thread thd2(Inf);

    pid_t pid1 = thd1.get_id();
    pid_t pid2 = thd2.get_id();

    thd1.swap(thd2);

    EXPECT_EQ(pid1, thd2.get_id());
    EXPECT_EQ(pid2, thd1.get_id());
}

TEST(MyThread_Test, Test_OperatorEq){
    my_thread thd1(Inf);
    my_thread thd2(Inf);

    pid_t pid1 = thd1.get_id();
    pid_t pid2 = thd2.get_id();

    thd1 = std::move(thd2);

    EXPECT_EQ(pid1, thd2.get_id());
    EXPECT_EQ(pid2, thd1.get_id());
}