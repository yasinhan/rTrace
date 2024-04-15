//
// Created by han on 4/10/24.
//
#include <gtest/gtest.h>
#include "src/primitive/color.h"
#include "src/pattern/gradient_pattern.h"
#include "src/shape/sphere.h"
#include "src/primitive/transformation.h"

class GradientPatternTest : public ::testing::Test {
protected:
    GradientPatternTest() = default;
    ~GradientPatternTest() override = default;
};

const Color white_ = Color(1, 1, 1);
const Color black_ = Color(0, 0, 0);

TEST(GRADIENT_PATTERN_TEST, INIT_TEST) {
    auto pattern = GradientPattern(white_, black_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0.25, 0, 0)), Color(0.75, 0.75, 0.75));
    ASSERT_EQ(pattern.color_at(Tuple::point(0.5, 0, 0)), Color(0.5, 0.5, 0.5));
    ASSERT_EQ(pattern.color_at(Tuple::point(0.75, 0, 0)), Color(0.25, 0.25, 0.25));

}