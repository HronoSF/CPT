#include <gtest/gtest.h>
#include "../../myproject/4/Guard.h"
#include <iostream>

using namespace std;

void print_hex(int i) {
    Guard g(cout);
    cout << hex << i;
}

TEST(Guard, correctness)
{
    ios_base::fmtflags flags = cout.flags();
    {
        Guard a(cout);
        cout.width(10);
        cout.fill('x');
        cout << hex;
        EXPECT_NE(flags, cout.flags());
    }
    EXPECT_EQ(flags, cout.flags());
}