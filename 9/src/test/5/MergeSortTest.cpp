#include "gtest/gtest.h"
#include <vector>
#include "../../myproject/5/MergeSort.h"

TEST(MERGE_SORT, NORMAL_VECTOR) {
    std::vector<int> v{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    merge_sort(v.begin(), v.end());
    for (int i = 0; i < 10; i++)
        EXPECT_EQ(v[i], i);
}

TEST(MERGE_SORT, ONE_ELEMENT_VECTOR) {
    std::vector<int> v{0};
    merge_sort(v.begin(), v.end());
    EXPECT_EQ(v[0], 0);
}