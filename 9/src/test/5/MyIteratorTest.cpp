#include <iostream>
#include "../../myproject/5/MyIterator.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(NTH_ITERATOR, correctness) {
    vector<int> data({1, 2, 3, 4, 5, 6, 7, 8, 9});
    ostringstream out;

    MyIterator<int, 9> a(out, " ");
    copy(data.data(), data.data() + 9, a);
    EXPECT_EQ(out.str(), "9");
    out.str("");

    MyIterator<int, 2> a2(out, " ");
    copy(data.data(), data.data() + 9, a2);
    EXPECT_EQ(out.str(), "2 4 6 8");
    out.str("");

    MyIterator<int, 4> a3(out, " ");
    copy(data.data(), data.data() + 9, a3);
    EXPECT_EQ(out.str(), "4 8");
}