#include <gtest/gtest.h>
#include "../../myproject/4/MyMatrix.h"


typedef float T;

struct myMatrix_param {
    std::vector<T> firstMatrix;
    std::vector<T> secondMatrix;
    std::vector<T> expectedResult;
};


class WhereMethodTest : public ::testing::TestWithParam<myMatrix_param> {};

INSTANTIATE_TEST_CASE_P(
        _,
        WhereMethodTest,
        ::testing::Values(
                myMatrix_param{
                        {100, 101, 3, 104},
                        { 200, 1, 2, 2 },
                        { 100, 1, 2, 2 }
                },
                myMatrix_param{
                        {-1, -2, -3, -4},
                        {200, 10, 2, -200},
                        {-1, -2, -3, -200}
                },
                myMatrix_param{
                        {1.2, 2.2},
                        {0,6.6},
                        {0, 2.2}
                }
        )
);


TEST_P(WhereMethodTest, _) {
    const myMatrix_param &dataProvider = GetParam();

    MyMatrix<T> firstMatrix{dataProvider.firstMatrix};
    MyMatrix<T> secondMatrix{dataProvider.secondMatrix};
    MyMatrix<T> resultAfterWhere = where(firstMatrix < secondMatrix, firstMatrix, secondMatrix);

    EXPECT_EQ(dataProvider.expectedResult, resultAfterWhere.getData());
}

