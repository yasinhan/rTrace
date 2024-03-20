//
// Created by han on 12/22/23.
//

#include <gtest/gtest.h>
#include "src/primitive/ray.h"
#include "src/primitive/transformation.h"
#include <cmath>

class RayTest : public ::testing::Test {
protected:
    RayTest() = default;
    ~RayTest() override = default;
};


TEST(RAY_TEST, TEST_POSITION) {
    auto ray = Ray(Tuple::point(2, 3, 4), Tuple::vector(1, 0, 0));

    auto pos_1 = ray.position(0);
    ASSERT_EQ(pos_1, Tuple::point(2, 3, 4));

    auto pos_2 = ray.position(1);
    ASSERT_EQ(pos_2, Tuple::point(3, 3, 4));

    auto pos_3 = ray.position(-1);
    ASSERT_EQ(pos_3, Tuple::point(1, 3, 4));

    auto pos_4 = ray.position(2.5);
    ASSERT_EQ(pos_4, Tuple::point(4.5, 3, 4));
}

TEST(RAY_TEST, TEST_TRANSLATION) {
    auto ray = Ray(Tuple::point(1, 2, 3), Tuple::vector(0, 1, 0));
    auto transform = translation(3, 4, 5);

    auto ret = ray.transform(transform);
    ASSERT_EQ(ret.get_origin(), Tuple::point(4, 6, 8));
    ASSERT_EQ(ret.get_direction(), Tuple::vector(0, 1, 0));
}

TEST(RAY_TEST, TEST_SCALING) {
    auto ray = Ray(Tuple::point(1, 2, 3), Tuple::vector(0, 1, 0));
    auto transform = scaling(2, 3, 4);

    auto ret = ray.transform(transform);
    ASSERT_EQ(ret.get_origin(), Tuple::point(2, 6, 12));
    ASSERT_EQ(ret.get_direction(), Tuple::vector(0, 3, 0));
}