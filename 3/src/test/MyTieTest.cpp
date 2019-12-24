#include <gtest/gtest.h>
#include "../myproject/MyTie.h"
#include <array>

TEST(MyTie, 2Arrays){
    std::array<float, 6> r{1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    std::array<float, 3> vec1, vec2;

    myTie(vec1, vec2) = r;

    EXPECT_EQ(vec1[0], 1.0f);
    EXPECT_EQ(vec1[1], 2.0f);
    EXPECT_EQ(vec1[2], 3.0f);
    EXPECT_EQ(vec2[0], 4.0f);
    EXPECT_EQ(vec2[1], 5.0f);
    EXPECT_EQ(vec2[2], 6.0f);
}

TEST(MyTie, 3Arrays){
    std::array<float, 6> r{1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    std::array<float, 2> vec1, vec2, vec3;

    myTie(vec1, vec2, vec3) = r;

    EXPECT_EQ(vec1[0], 1.0f);
    EXPECT_EQ(vec1[1], 2.0f);
    EXPECT_EQ(vec2[0], 3.0f);
    EXPECT_EQ(vec2[1], 4.0f);
    EXPECT_EQ(vec3[0], 5.0f);
    EXPECT_EQ(vec3[1], 6.0f);
}