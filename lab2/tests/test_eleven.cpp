#include <gtest/gtest.h>
#include "Eleven.h"

TEST(ElevenTest, Addition) {
    Eleven num1("1A2");
    Eleven num2("34");
    Eleven expected("216");
    EXPECT_EQ(num1 + num2, expected);
}

TEST(ElevenTest, Subtraction) {
    Eleven num1("1A2");
    Eleven num2("34");
    Eleven expected("168");
    EXPECT_EQ(num1 - num2, expected);
}

TEST(ElevenTest, Equality) {
    Eleven num1("1A2");
    Eleven num2("1A2");
    EXPECT_EQ(num1, num2);
}

TEST(ElevenTest, Inequality) {
    Eleven num1("1A2");
    Eleven num2("34");
    EXPECT_NE(num1, num2);
}

TEST(ElevenTest, LessThan) {
    Eleven num1("34");
    Eleven num2("1A2");
    EXPECT_LT(num1, num2);
}

TEST(ElevenTest, GreaterThan) {
    Eleven num1("1A2");
    Eleven num2("34");
    EXPECT_GT(num1, num2);
}

TEST(ElevenTest, LessThanOrEqual) {
    Eleven num1("34");
    Eleven num2("1A2");
    EXPECT_LE(num1, num2);
}

TEST(ElevenTest, GreaterThanOrEqual) {
    Eleven num1("1A2");
    Eleven num2("34");
    EXPECT_GE(num1, num2);
}
