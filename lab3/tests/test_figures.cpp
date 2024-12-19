#include <gtest/gtest.h>
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"

TEST(TrapezoidTest, Area) {
    Trapezoid trapezoid(3, 4, 5);
    EXPECT_DOUBLE_EQ(trapezoid.getArea(), 17.5);
}

TEST(TrapezoidTest, GeometricCenter) {
    Trapezoid trapezoid(3, 4, 5);
    auto center = trapezoid.getGeometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 3.5);
    EXPECT_DOUBLE_EQ(center.second, 2.5);
}

TEST(RhombusTest, Area) {
    Rhombus rhombus(6, 7);
    EXPECT_DOUBLE_EQ(rhombus.getArea(), 42);
}

TEST(RhombusTest, GeometricCenter) {
    Rhombus rhombus(6, 7);
    auto center = rhombus.getGeometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 3);
    EXPECT_DOUBLE_EQ(center.second, 3.5);
}

TEST(PentagonTest, Area) {
    Pentagon pentagon(8);
    EXPECT_DOUBLE_EQ(pentagon.getArea(), 148.3095238095238);
}

TEST(PentagonTest, GeometricCenter) {
    Pentagon pentagon(8);
    auto center = pentagon.getGeometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 4);
    EXPECT_DOUBLE_EQ(center.second, 4);
}
