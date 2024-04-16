//
// Created by han on 4/10/24.
//
#include <gtest/gtest.h>
#include "src/primitive/color.h"
#include "src/pattern/checkers_pattern.h"
#include "src/shape/sphere.h"

class CheckersPatternTest : public ::testing::Test {
protected:
    CheckersPatternTest() = default;
    ~CheckersPatternTest() override = default;
};

const Color white_ = Color(1, 1, 1);
const Color black_ = Color(0, 0, 0);

TEST(CHECKERS_PATTERN_TEST, TEST_CHECKERS_REPEAT_IN_X) {
    auto pattern = CheckersPattern(white_, black_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0.99, 0, 0)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(1.01, 0, 0)), black_);
}

TEST(CHECKERS_PATTERN_TEST, TEST_CHECKERS_REPEAT_IN_Y) {
    auto pattern = CheckersPattern(white_, black_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0.99, 0)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 1.01, 0)), black_);
}

TEST(CHECKERS_PATTERN_TEST, TEST_CHECKERS_REPEAT_IN_Z) {
    auto pattern = CheckersPattern(white_, black_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 0.99)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 1.01)), black_);
}