//
// Created by han on 1/8/24.
//

#include "src/primitive/color.h"
#include "src/canvas.h"
#include <gtest/gtest.h>
#include <cmath>
#include "src/math.h"

class CanvasTest : public ::testing::Test {
protected:
    CanvasTest() = default;
    ~CanvasTest() override = default;
};

TEST(CANVAS_TEST, TEST_CREATE) {
    auto canvas = new Canvas(3, 3);
    auto color_0_0 = canvas->pixel_at(0, 0);

    EXPECT_TRUE(epsilon(color_0_0.getRed(), 0.0));
    EXPECT_TRUE(epsilon(color_0_0.getGreen(), 0.0));
    EXPECT_TRUE(epsilon(color_0_0.getBlue(), 0.0));

    auto color_0_1 = canvas->pixel_at(0, 1);

    EXPECT_TRUE(epsilon(color_0_1.getRed(), 0.0));
    EXPECT_TRUE(epsilon(color_0_1.getGreen(), 0.0));
    EXPECT_TRUE(epsilon(color_0_1.getBlue(), 0.0));
}

TEST(CANVAS_TEST, TEST_WRITE) {
    auto canvas = new Canvas(3, 3);
    auto color = new Color(1, 0.1, 0.5);
    canvas->write_pixel(0, 1, *color);

    auto color_in = canvas->pixel_at(0, 1);

    EXPECT_TRUE(epsilon(color_in.getRed(), 1));
    EXPECT_TRUE(epsilon(color_in.getGreen(), 0.1));
    EXPECT_TRUE(epsilon(color_in.getBlue(), 0.5));
}