#include <gtest/gtest.h>
#include "../myproject/MyCat.h"
#include <array>

TEST(myCat, CheckOn2Arrays){
    std::array<float, 3> vec1{1.0f, 2.0f, 3.0f};
    std::array<float, 3> vec2{4.0f, 5.0f, 6.0f};

    std::array<float, 6> r = myCat(vec1, vec2);

    EXPECT_EQ(r[0], 1.0f);
    EXPECT_EQ(r[1], 2.0f);
    EXPECT_EQ(r[2], 3.0f);
    EXPECT_EQ(r[3], 4.0f);
    EXPECT_EQ(r[4], 5.0f);
    EXPECT_EQ(r[5], 6.0f);
}

TEST(myCat, CheckOn2ArraysOfDifSize){
    std::array<float, 3> vec1{1.0f, 2.0f, 3.0f};
    std::array<float, 2> vec2{4.0f, 5.0f};

    std::array<float, 5> r = myCat(vec1, vec2);

    EXPECT_EQ(r[0], 1.0f);
    EXPECT_EQ(r[1], 2.0f);
    EXPECT_EQ(r[2], 3.0f);
    EXPECT_EQ(r[3], 4.0f);
    EXPECT_EQ(r[4], 5.0f);
}

TEST(myCat, CheckOn3ArraysOfDifSize){
    std::array<float, 3> vec1{1.0f, 2.0f, 3.0f};
    std::array<float, 2> vec2{4.0f, 5.0f};
    std::array<float, 3> vec3{6.0f, 7.0f, 8.0f};

    std::array<float, 8> r = myCat(vec1, vec2, vec3);

    EXPECT_EQ(r[0], 1.0f);
    EXPECT_EQ(r[1], 2.0f);
    EXPECT_EQ(r[2], 3.0f);
    EXPECT_EQ(r[3], 4.0f);
    EXPECT_EQ(r[4], 5.0f);
    EXPECT_EQ(r[5], 6.0f);
    EXPECT_EQ(r[6], 7.0f);
    EXPECT_EQ(r[7], 8.0f);
}

TEST(myCat, CheckOn1Array){
    std::array<float, 3> vec1{1.0f, 2.0f, 3.0f};

    std::array<float, 3> r = myCat(vec1);

    EXPECT_EQ(r[0], 1.0f);
    EXPECT_EQ(r[1], 2.0f);
    EXPECT_EQ(r[2], 3.0f);
}