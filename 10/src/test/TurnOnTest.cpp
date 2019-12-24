#include <gtest/gtest.h>
#include <vector>
#include "../myproject/TurnOn.h"

TEST(TURN90, SIZE){
    std::vector<int> vec = {1,2,3};
    EXPECT_FALSE(turnOnVector(vec, 90));
}

TEST(TURN90, MULTIPLICITY){
    std::vector<int> vec = {1,2};
    EXPECT_FALSE(turnOnVector(vec, 100));
}

TEST(TURN90, CW_90_DEG){
    std::vector<int> vec = {1,2};
    turnOnVector(vec, 90);
    EXPECT_EQ(2, vec[0]);
    EXPECT_EQ(-1, vec[1]);
}

TEST(TURN90, CCW_90_DEG){
    std::vector<int> vec = {1,2};
    turnOnVector(vec, -90);
    EXPECT_EQ(-2, vec[0]);
    EXPECT_EQ(1, vec[1]);
}