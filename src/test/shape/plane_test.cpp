//
// Created by han on 4/9/24.
//
#include <gtest/gtest.h>
#include <cmath>
#include "src/shape/plane.h"

class PlaneTest : public ::testing::Test {
protected:
    PlaneTest() = default;
    ~PlaneTest() override = default;
};

TEST(PLANE_TEST, TEST_LOCAL_NORMAL_AT) {
    auto plane = Plane();

    auto n1 = plane.local_normal_at(Tuple::point(0, 0, 0));
    auto n2 = plane.local_normal_at(Tuple::point(10, 0, -10));
    auto n3 = plane.local_normal_at(Tuple::point(-5, 0, 150));

    auto normal = Tuple::vector(0, 1, 0);
    ASSERT_EQ(n1, normal);
    ASSERT_EQ(n2, normal);
    ASSERT_EQ(n3, normal);
}