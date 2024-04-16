//
// Created by han on 4/10/24.
//
#include <gtest/gtest.h>
#include "src/primitive/color.h"
#include "src/pattern/ring_pattern.h"
#include "src/shape/sphere.h"

class RingPatternTest : public ::testing::Test {
protected:
    RingPatternTest() = default;
    ~RingPatternTest() override = default;
};

const Color white_ = Color(1, 1, 1);
const Color black_ = Color(0, 0, 0);

TEST(RING_PATTERN_TEST, TEST_COLOR_AT) {
    auto pattern = RingPattern(white_, black_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.color_at(Tuple::point(1, 0, 0)), black_);
    ASSERT_EQ(pattern.color_at(Tuple::point(0, 0, 1)), black_);
}
