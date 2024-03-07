//
// Created by han on 12/22/23.
//

#include <gtest/gtest.h>
#include "src/primitive/ray.h"
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
