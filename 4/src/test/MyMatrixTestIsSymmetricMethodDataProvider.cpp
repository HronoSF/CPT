#include <gtest/gtest.h>
#include "../myproject/MyMatrix.h"

typedef float T;

struct myMatrix_param {
    std::vector<T> matrix;
    double epsilon;
    int n;
    int m;
    bool expectedOutput;
};


class IsSymmetricMethodTest : public ::testing::TestWithParam<myMatrix_param> {
};

INSTANTIATE_TEST_CASE_P(
        _,
        IsSymmetricMethodTest,
        ::testing::Values(
                myMatrix_param{
                        {2, 1, -2,
                                1, 0, 3,
                                -2, 3, -4},
                        1,
                        3,
                        3,
                        true
                },
                myMatrix_param{
                        {1, 89,
                         0, 1},
                        1,
                        2,
                        2,
                        false
                },
                myMatrix_param{
                        {0, 89,
                         89, 0},
                        1,
                        2,
                        2,
                        true
                }
        )
);


TEST_P(IsSymmetricMethodTest, _) {
    const myMatrix_param &dataProvider = GetParam();
    MyMatrix<T> matrix{dataProvider.matrix};
    EXPECT_EQ(dataProvider.expectedOutput,matrix.is_symmetric(dataProvider.epsilon,dataProvider.n,dataProvider.m));
}

