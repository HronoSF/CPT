#include <gtest/gtest.h>
#include "../myproject/MyMessage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

TEST(MyMessage, SizeFalse) {
    EXPECT_FALSE(message(std::cout, "% + % = %", "a", 1));
    EXPECT_FALSE(message(std::cout, "% + % = %", "a", 1, 3.0, 4.5));
}

TEST(MyMessage, String) {
    std::stringstream strStreamOut;

    message(strStreamOut, "% + % = %", "a", 1, 3.0);

    std::string strOut = strStreamOut.str();
    std::string str2 = "a + 1 = 3";
    EXPECT_EQ(strOut, str2);
}