#include <gtest/gtest.h>
#include "../myproject/ln80c_buffer.h"
#include <ostream>

TEST(LN80C_BUFFER, TEST_2_STRINGS){
    std::stringbuf strBuf;
    ln80c_buffer buf = ln80c_buffer(&strBuf);
    std::ostream ost(&buf);

    ost<<"Hello";
    EXPECT_EQ(strBuf.str(), "1       Hello");
    ost<<'\n';
    ost<<"World";
    EXPECT_EQ(strBuf.str(), "1       Hello\n2       World");

}

TEST(LN80C_BUFFER, TEST_72_CHARS){
    std::stringbuf strBuf;
    ln80c_buffer buf = ln80c_buffer(&strBuf);
    std::ostream ost(&buf);

    std::string str = std::string(72, '1');
    ost<<str;
    EXPECT_EQ(strBuf.str(), "1       " + str + '\n');
    ost<<"123";
    EXPECT_EQ(strBuf.str(), "1       " + str + "\n2       123");
}

TEST(LN80C_BUFFER, TEST_MORE_THAN_72_CHARS){
    std::stringbuf strBuf;
    ln80c_buffer buf = ln80c_buffer(&strBuf);
    std::ostream ost(&buf);

    std::string str1 = std::string(72, '1');
    std::string str2 = std::string(2, '1');
    ost<<str1+str2;
    EXPECT_EQ(strBuf.str(), "1       " + str1 + '\n' + "2       " + str2);
}