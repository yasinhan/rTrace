//
// Created by han on 3/28/24.
//
#include <gtest/gtest.h>
#include "src/scene/prepare_computations.h"
#include "src/shape/sphere.h"

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