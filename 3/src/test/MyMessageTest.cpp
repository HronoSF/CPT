#include <gtest/gtest.h>
#include "../myproject/MyMessage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

TEST(message, basicTest) {
    char ans[] = "a + 5 = 10";
    std::stringstream ss;
    message(ss, "% + % = %", 'a', 5, 10.0);
    EXPECT_EQ(ans, ss.str());
}

TEST(message, unequalityOfPercentsTest) {
    char ans[] = "a + 5 = 10";
    std::stringstream ss;
    message(ss, "% + % = %%% %", 'a', 5, 10.0);
    EXPECT_EQ(ans, ss.str());
}