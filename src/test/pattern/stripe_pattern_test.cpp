//
// Created by han on 4/10/24.
//
#include <gtest/gtest.h>
#include "src/primitive/color.h"
#include "src/pattern/stripe_pattern.h"

class StripePatternTest : public ::testing::Test {
protected:
    StripePatternTest() = default;
    ~StripePatternTest() override = default;
};

const Color white_ = Color(1, 1, 1);
const Color black_ = Color(0, 0, 0);

TEST(STRIPE_PATTERN_TEST, INIT_TEST) {
    auto pattern = StripePattern(white_, black_);
    ASSERT_EQ(pattern.color_a(), white_);
    ASSERT_EQ(pattern.color_b(), black_);
}