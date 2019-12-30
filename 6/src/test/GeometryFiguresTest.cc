#include "gtest/gtest.h"
#include "../myproject/GeometryFigures.h"

TEST(GEOMETRY, CIRCLE_TRAIT){
Circle c = Circle(1);

EXPECT_EQ(sizeof(1), std::Trait<Circle>::size(c));
}

TEST(GEOMETRY, RECTANGLE_TRAIT){
Rectangle r = Rectangle(1, 2);

EXPECT_EQ(sizeof(1) + sizeof(2), std::Trait<Rectangle>::size(r));
}
