//
// Created by han on 1/8/24.
//

#include <gtest/gtest.h>
#include <cmath>
#include "src/shape/material.h"

class MaterialTest : public ::testing::Test {
protected:
    MaterialTest() = default;
    ~MaterialTest() override = default;
};

TEST(MATERIAL_TEST, TEST_LIGHTING_EYE_BETWEEN_SURFACE) {
    auto m = Material();
    auto position = Tuple::point(0, 0, 0);

    auto eye = Tuple::vector(0, 0, -1);
    auto normal = Tuple::vector(0, 0, -1);
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 0, -10));

    auto ret = m.lighting(light, position, eye, normal, false);
    ASSERT_EQ(ret, Color(1.9, 1.9, 1.9));
}

TEST(MATERIAL_TEST, TEST_LIGHTING_EYE_BETWEEN_SURFACE_AND_45) {
    auto m = Material();
    auto position = Tuple::point(0, 0, 0);

    auto eye = Tuple::vector(0, (float )sqrt(2) / 2, -(float )sqrt(2) / 2);
    auto normal = Tuple::vector(0, 0, -1);
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 0, -10));

    auto ret = m.lighting(light, position, eye, normal, false);
    ASSERT_EQ(ret, Color(1.0, 1.0, 1.0));
}

TEST(MATERIAL_TEST, TEST_LIGHTING_EYE_OPPOSITE_SURFACE_LIGHT_45) {
    auto m = Material();
    auto position = Tuple::point(0, 0, 0);

    auto eye = Tuple::vector(0, 0, -1);
    auto normal = Tuple::vector(0, 0, -1);
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 10, -10));

    auto ret = m.lighting(light, position, eye, normal, false);
    ASSERT_EQ(ret, Color(0.7364, 0.7364, 0.7364));
}

TEST(MATERIAL_TEST, TEST_LIGHTING_EYE_45_LIGHT_45_SURFACE) {
    auto m = Material();
    auto position = Tuple::point(0, 0, 0);

    auto eye = Tuple::vector(0, -(float ) sqrt(2) / 2, -(float )sqrt(2) / 2);
    auto normal = Tuple::vector(0, 0, -1);
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 10, -10));

    auto ret = m.lighting(light, position, eye, normal, false);
    ASSERT_EQ(ret, Color(1.6364, 1.6364, 1.6364));
}

TEST(MATERIAL_TEST, TEST_LIGHTING_LIGHT_BEHIND_SURFACE) {
    auto m = Material();
    auto position = Tuple::point(0, 0, 0);

    auto eye = Tuple::vector(0, 0, -1);
    auto normal = Tuple::vector(0, 0, -1);
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 0, 10));

    auto ret = m.lighting(light, position, eye, normal, false);
    ASSERT_EQ(ret, Color(0.1, 0.1, 0.1));
}

TEST(MATERIAL_TEST, TEST_LIGHTING_WITH_SURFACE_IN_SHADOW) {
    auto m = Material();
    auto position = Tuple::point(0, 0, 0);

    auto eye = Tuple::vector(0, 0, -1);
    auto normal = Tuple::vector(0, 0, -1);
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 0, -10));

    auto ret = m.lighting(light, position, eye, normal, true);
    ASSERT_EQ(ret, Color(0.1, 0.1, 0.1));
}