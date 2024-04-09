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

TEST(PLANE_TEST, TEST_INTERSECT_WITH_RAY_PARALLEL) {
    auto plane = Plane();

    auto ray = Ray(Tuple::point(0, 10, 0), Tuple::vector(0, 0, 1));
    auto intersections = plane.intersect_with(ray);
    ASSERT_TRUE(intersections.count() == 0);

    auto ray_1 = Ray(Tuple::point(0, 0, 0), Tuple::vector(0, 0, 1));
    auto intersections_1 = plane.intersect_with(ray_1);
    ASSERT_TRUE(intersections_1.count() == 0);
}

TEST(PLANE_TEST, TEST_INTERSECT_WITH_RAY_ABOVE) {
    auto plane = Plane();

    auto ray = Ray(Tuple::point(0, 1, 0), Tuple::vector(0, -1, 0));
    auto intersections = plane.intersect_with(ray);
    ASSERT_EQ(intersections.count(), 1);
    ASSERT_FLOAT_EQ(intersections[0].get_t(), 1);
    ASSERT_EQ(intersections[0].get_obj(), &plane);
}

TEST(PLANE_TEST, TEST_INTERSECT_WITH_RAY_BELOW) {
    auto plane = Plane();

    auto ray = Ray(Tuple::point(0, -1, 0), Tuple::vector(0, 1, 0));
    auto intersections = plane.intersect_with(ray);
    ASSERT_EQ(intersections.count(), 1);
    ASSERT_FLOAT_EQ(intersections[0].get_t(), 1);
    ASSERT_EQ(intersections[0].get_obj(), &plane);
}