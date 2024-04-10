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

TEST(STRIPE_PATTERN_TEST, TEST_CONSTANT_IN_Y) {
    auto pattern = StripePattern(white_, black_);

    ASSERT_EQ(pattern.stripe_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(0, 1, 0)), white_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(0, 2, 0)), white_);
}

TEST(STRIPE_PATTERN_TEST, TEST_CONSTANT_IN_Z) {
    auto pattern = StripePattern(white_, black_);

    ASSERT_EQ(pattern.stripe_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(0, 0, 1)), white_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(0, 0, 2)), white_);
}

TEST(STRIPE_PATTERN_TEST, TEST_ALTERNATES_IN_X) {
    auto pattern = StripePattern(white_, black_);

    ASSERT_EQ(pattern.stripe_at(Tuple::point(0, 0, 0)), white_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(0.9, 0, 0)), white_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(1, 0, 0)), black_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(-0.1, 0, 0)), black_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(-1, 0, 0)), black_);
    ASSERT_EQ(pattern.stripe_at(Tuple::point(-1.1, 0, 0)), white_);
}