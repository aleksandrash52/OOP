#include <gtest/gtest.h>
#include "is_valid_parentheses.h"

TEST(IsValidParenthesesTest, EmptyString) {
    EXPECT_TRUE(is_valid_parentheses(""));
}

TEST(IsValidParenthesesTest, SinglePair) {
    EXPECT_TRUE(is_valid_parentheses("()"));
}

TEST(IsValidParenthesesTest, UnmatchedClosing) {
    EXPECT_FALSE(is_valid_parentheses(")"));
}

TEST(IsValidParenthesesTest, UnmatchedOpening) {
    EXPECT_FALSE(is_valid_parentheses("("));
}

TEST(IsValidParenthesesTest, MultiplePairs) {
    EXPECT_TRUE(is_valid_parentheses("(())"));
}

TEST(IsValidParenthesesTest, NestedPairs) {
    EXPECT_TRUE(is_valid_parentheses("((()))"));
}

TEST(IsValidParenthesesTest, MixedPairs) {
    EXPECT_TRUE(is_valid_parentheses("()()"));
}

TEST(IsValidParenthesesTest, ComplexValid) {
    EXPECT_TRUE(is_valid_parentheses("(())((()())())"));
}

TEST(IsValidParenthesesTest, ComplexInvalid) {
    EXPECT_FALSE(is_valid_parentheses(")(()))"));
}
