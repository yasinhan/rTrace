//
// Created by han on 1/8/24.
//

#include "src/primitive/color.h"
#include <gtest/gtest.h>
#include <cmath>
#include "src/math.h"

TEST(COLOR_TEST, TEST_CREATE) {
    auto color = Color(0.5, 0.4, 1.7);

    EXPECT_TRUE(epsilon(color.get_red(), 0.5));
    EXPECT_TRUE(epsilon(color.get_green(), 0.4));
    EXPECT_TRUE(epsilon(color.get_blue(), 1.7));
}

TEST(COLOR_TEST, ADD_TEST) {
    auto color_1 = Color(0.9, 0.6, 0.75);
    auto color_2 = Color(0.7, 0.1, 0.25);

    auto add_result = color_1 + color_2;

    EXPECT_TRUE(epsilon(add_result.get_red(), 1.6));
    EXPECT_TRUE(epsilon(add_result.get_green(), 0.7));
    EXPECT_TRUE(epsilon(add_result.get_blue(), 1.0));
}

TEST(COLOR_TEST, SUBTRACT_TEST) {
    auto color_1 = Color(0.9, 0.6, 0.75);
    auto color_2 = Color(0.7, 0.1, 0.25);

    auto subtract_result = color_1 - color_2;

    EXPECT_TRUE(epsilon(subtract_result.get_red(), 0.2));
    EXPECT_TRUE(epsilon(subtract_result.get_green(), 0.5));
    EXPECT_TRUE(epsilon(subtract_result.get_blue(), 0.5));
}

TEST(COLOR_TEST, MULTIPLY_TEST) {
    auto color_1 = Color(0.9, 0.6, 0.75);

    auto multiply_result = color_1 * 2;

    EXPECT_TRUE(epsilon(multiply_result.get_red(), 1.8));
    EXPECT_TRUE(epsilon(multiply_result.get_green(), 1.2));
    EXPECT_TRUE(epsilon(multiply_result.get_blue(), 1.5));
}

TEST(COLOR_TEST, EQUAL_TEST) {
    auto color_1 = Color(0.9, 0.6, 0.75);
    auto color_2 = Color(0.9, 0.6, 0.75);

    ASSERT_EQ(color_1, color_2);
}