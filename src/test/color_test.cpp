//
// Created by han on 1/8/24.
//

#include "src/primitive/color.h"
#include <gtest/gtest.h>
#include <cmath>
#include "src/math.h"

TEST(COLOR_TEST, TEST_CREATE) {
    auto color = new Color(0.5, 0.4, 1.7);

    EXPECT_EQ(color->getRed(), 0.5);
    EXPECT_TRUE(epsilon(color->getGreen(), 0.4));
    EXPECT_TRUE(epsilon(color->getBlue(), 1.7));
}

