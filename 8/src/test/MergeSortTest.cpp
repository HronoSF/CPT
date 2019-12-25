#include <gtest/gtest.h>
#include <vector>
#include "../myproject/MergeSort.h"

TEST(MERGE_SORT_THREAD, NORMAL_VECTOR){
std::vector<int> v1{9,8,7,6,5,4,3,2,1,0};
std::vector<int> v2{9,8,7,6,5,4,3,2,1,0};
MergeSortConsistent(v1.begin(), v1.end());
MergeSortInThreads(v2.begin(), v2.end(),1);

for(int i=0; i<10; i++)
EXPECT_EQ(v1[i], v2[i]);
}

TEST(MERGE_SORT_THREAD, ONE_ELEMENT_VECTOR){
std::vector<int> v{0};
MergeSortInThreads(v.begin(), v.end(),1);
EXPECT_EQ(v[0], 0);
}