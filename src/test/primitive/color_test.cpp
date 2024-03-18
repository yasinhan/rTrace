//
// Created by han on 1/8/24.
//

#include "src/primitive/color.h"
#include <gtest/gtest.h>
#include <cmath>
#include "src/math.h"

TEST(COLOR_TEST, TEST_CREATE) {
    auto color = new Color(0.5, 0.4, 1.7);

    EXPECT_TRUE(epsilon(color->getRed(), 0.5));
    EXPECT_TRUE(epsilon(color->getGreen(), 0.4));
    EXPECT_TRUE(epsilon(color->getBlue(), 1.7));
}

TEST(COLOR_TEST, ADD_TEST) {
    auto color_1 = new Color(0.9, 0.6, 0.75);
    auto color_2 = new Color(0.7, 0.1, 0.25);

    auto add_result = *color_1 + *color_2;

    EXPECT_TRUE(epsilon(add_result.getRed(), 1.6));
    EXPECT_TRUE(epsilon(add_result.getGreen(), 0.7));
    EXPECT_TRUE(epsilon(add_result.getBlue(), 1.0));
}

TEST(COLOR_TEST, SUBTRACT_TEST) {
    auto color_1 = new Color(0.9, 0.6, 0.75);
    auto color_2 = new Color(0.7, 0.1, 0.25);

    auto subtract_result = *color_1 - *color_2;

    EXPECT_TRUE(epsilon(subtract_result.getRed(), 0.2));
    EXPECT_TRUE(epsilon(subtract_result.getGreen(), 0.5));
    EXPECT_TRUE(epsilon(subtract_result.getBlue(), 0.5));
}

TEST(COLOR_TEST, MULTIPLY_TEST) {
    auto color_1 = new Color(0.9, 0.6, 0.75);

    auto multiply_result = *color_1 * 2;

    EXPECT_TRUE(epsilon(multiply_result.getRed(), 1.8));
    EXPECT_TRUE(epsilon(multiply_result.getGreen(), 1.2));
    EXPECT_TRUE(epsilon(multiply_result.getBlue(), 1.5));
}