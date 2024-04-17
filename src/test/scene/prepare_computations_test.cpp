//
// Created by han on 3/28/24.
//
#include <gtest/gtest.h>
#include "src/scene/prepare_computations.h"
#include "src/shape/sphere.h"
#include "src/shape/plane.h"
#include "src/primitive/transformation.h"
#include "src/primitive/tuple.h"
#include "src/math.h"
#include <cmath>

class PrepareComputationsTest : public ::testing::Test {
protected:
    PrepareComputationsTest() = default;
    ~PrepareComputationsTest() override = default;
};

TEST(PREPARE_COMPUTATIONS_TEST, TEST_INIT) {
    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto shape = Sphere();
    auto intersections = shape.intersect(ray);

    auto intersection = intersections[0];

    auto prepare = PrepareComputations(intersection, intersections, ray);
    ASSERT_FLOAT_EQ(prepare.get_t(), intersection.get_t());
    ASSERT_EQ(prepare.get_object(), intersection.get_obj());
    ASSERT_EQ(prepare.get_point(), Tuple::point(0, 0, -1));
    ASSERT_EQ(prepare.get_eye_vector(), Tuple::vector(0, 0, -1));
    ASSERT_EQ(prepare.get_normal_vector(), Tuple::vector(0, 0, -1));
}

TEST(PREPARE_COMPUTATIONS_TEST, TEST_INSIDE) {
    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto shape = Sphere();
    auto intersections = shape.intersect(ray);

    auto intersection = intersections[0];

    auto prepare_1 = PrepareComputations(intersection, intersections, ray);
    ASSERT_FALSE(prepare_1.is_inside());

    auto ray_1 = Ray(Tuple::point(0, 0, 0), Tuple::vector(0, 0, 1));
    auto intersections_1 = shape.intersect(ray_1);
    auto intersection_1 = intersections_1.hit().value();

    auto prepare_2 = PrepareComputations(intersection_1, intersections_1, ray_1);
    ASSERT_TRUE(prepare_2.is_inside());
    ASSERT_EQ(prepare_2.get_normal_vector(), Tuple::vector(0, 0, -1));
}

TEST(PREPARE_COMPUTATIONS, TEST_HIT_OFFSET_POINT) {
    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto shape = Sphere();
    shape.set_transform(translation(0, 0, 1));

    auto intersections = shape.intersect(ray);
    auto intersection = intersections.hit();
    ASSERT_TRUE(intersection.has_value());

    auto prepare = PrepareComputations(intersection.value(), intersections, ray);
    ASSERT_TRUE(prepare.get_over_point().getZ() < EPSILON / 2);
    ASSERT_TRUE(prepare.get_point().getZ() > prepare.get_over_point().getZ());
}

TEST(PREPARE_COMPUTATIONS, TEST_COMPUTE_REFLECT_VECTOR) {
    auto ray = Ray(Tuple::point(0, 1, -1), Tuple::vector(0, -(float ) sqrt(2) / 2, (float ) sqrt(2) / 2));
    auto shape = Plane();

    auto intersections = shape.intersect(ray);
    auto intersection = intersections.hit();
    ASSERT_TRUE(intersection.has_value());

    auto prepare = PrepareComputations(intersection.value(), intersections, ray);
    ASSERT_EQ(prepare.get_reflect_vector(), Tuple::vector(0, sqrt(2) / 2, sqrt(2) / 2));
}