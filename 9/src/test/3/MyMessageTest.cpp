#include <gtest/gtest.h>
#include "../../myproject/3/MyMessage.h"
#include <string>

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