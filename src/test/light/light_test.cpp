//
// Created by han on 3/20/24.
//

#include <gtest/gtest.h>
#include "src/light/light.h"

class LightTest : public ::testing::Test {
protected:
    LightTest() = default;
    ~LightTest() override = default;
};

TEST(LIGHT_TEST, TEST_CREATE) {
    auto intensity = Color(1, 1, 1);
    auto position = Tuple::point(0, 0, 0);
    auto light = Light(intensity, position);
    ASSERT_EQ(light.get_intensity(), intensity);
    ASSERT_EQ(light.get_position(), position);
}