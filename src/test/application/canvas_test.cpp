//
// Created by han on 1/8/24.
//

#include "src/primitive/color.h"
#include "src/application/canvas.h"
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

    EXPECT_TRUE(epsilon(color_0_0.get_red(), 0.0));
    EXPECT_TRUE(epsilon(color_0_0.get_green(), 0.0));
    EXPECT_TRUE(epsilon(color_0_0.get_blue(), 0.0));

    auto color_0_1 = canvas->pixel_at(0, 1);

    EXPECT_TRUE(epsilon(color_0_1.get_red(), 0.0));
    EXPECT_TRUE(epsilon(color_0_1.get_green(), 0.0));
    EXPECT_TRUE(epsilon(color_0_1.get_blue(), 0.0));
}

TEST(CANVAS_TEST, TEST_WRITE) {
    auto canvas = new Canvas(3, 3);
    auto color = new Color(1, 0.1, 0.5);
    canvas->write_pixel(0, 1, *color);

    auto color_in = canvas->pixel_at(0, 1);

    EXPECT_TRUE(epsilon(color_in.get_red(), 1));
    EXPECT_TRUE(epsilon(color_in.get_green(), 0.1));
    EXPECT_TRUE(epsilon(color_in.get_blue(), 0.5));
}