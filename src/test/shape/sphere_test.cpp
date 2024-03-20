//
// Created by han on 1/8/24.
//

#include <gtest/gtest.h>
#include <cmath>
#include "src/shape/sphere.h"
#include "src/primitive/transformation.h"

class SphereTest : public ::testing::Test {
protected:
    SphereTest() = default;
    ~SphereTest() override = default;
};

TEST(SPHERE_TEST, TEST_INTERSECT) {
    auto ray_0 = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto s = Sphere();

    auto intersection = s.intersect(ray_0);

    ASSERT_EQ(intersection.count(), 2);
    ASSERT_FLOAT_EQ(intersection[0].get_t(), 4.0);
    ASSERT_FLOAT_EQ(intersection[1].get_t(), 6.0);
    ASSERT_EQ(intersection[0].get_obj(), &s);

    auto ray_1 = Ray(Tuple::point(0, 2, -5), Tuple::vector(0, 0, 1));
    auto intersection_1 = s.intersect(ray_1);
    ASSERT_EQ(intersection_1.count(), 0);

    auto ray_2 = Ray(Tuple::point(0, 1, -5), Tuple::vector(0, 0, 1));
    auto intersection_2 = s.intersect(ray_2);
    ASSERT_EQ(intersection_2.count(), 2);
    ASSERT_FLOAT_EQ(intersection_2[0].get_t(), 5.0);
    ASSERT_FLOAT_EQ(intersection_2[1].get_t(), 5.0);

    auto ray_3 = Ray(Tuple::point(0, 0, 0), Tuple::vector(0, 0, 1));
    auto intersection_3 = s.intersect(ray_3);
    ASSERT_EQ(intersection_3.count(), 2);
    ASSERT_FLOAT_EQ(intersection_3[0].get_t(), -1.0);
    ASSERT_FLOAT_EQ(intersection_3[1].get_t(), 1.0);
}

TEST(SPHERE_TEST, TEST_SCALING) {
    auto s = Sphere();
    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));

    s.set_transform(scaling(2, 2, 2));
    auto intersection = s.intersect(ray);
    ASSERT_EQ(intersection.count(), 2);
    ASSERT_FLOAT_EQ(intersection[0].get_t(), 3);
    ASSERT_FLOAT_EQ(intersection[1].get_t(), 7);
}

TEST(SPHERE_TEST, TEST_TRANSLATION) {
    auto s = Sphere();
    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));

    s.set_transform(translation(5, 0, 0));
    auto intersection = s.intersect(ray);
    ASSERT_EQ(intersection.count(), 0);
}

TEST(SPHERE_TEST, TEST_NORMAL_AT) {
    auto s = Sphere();

    auto n_0 = s.normal_at(Tuple::point(1, 0, 0));
    ASSERT_EQ(n_0, Tuple::vector(1, 0, 0));

    auto n_1 = s.normal_at(Tuple::point(0, 1, 0));
    ASSERT_EQ(n_1, Tuple::vector(0, 1, 0));

    auto n_2 = s.normal_at(Tuple::point(0, 0, 1));
    ASSERT_EQ(n_2, Tuple::vector(0, 0, 1));

    float sqrt_3 = sqrt(3) / 3;
    auto n_3 = s.normal_at(Tuple::point(sqrt_3, sqrt_3, sqrt_3));
    ASSERT_EQ(n_3, Tuple::vector(sqrt_3, sqrt_3, sqrt_3));
}

TEST(SPHERE_TEST, TEST_NORMAL_AT_WITH_TRANS) {
    auto s = Sphere();

    s.set_transform(translation(0, 1, 0));
    auto n = s.normal_at(Tuple::point(0, 1.70711, -0.70711));
    ASSERT_EQ(n, Tuple::vector(0, 0.70711, -0.70711));

    s.set_transform(scaling(1, 0.5, 1) * rotate_z(M_PI / 5));
    auto n_1 = s.normal_at(Tuple::point(0, sqrt(2) / 2, -sqrt(2) / 2));
    ASSERT_EQ(n_1, Tuple::vector(0, 0.97014, -0.24254));
}

TEST(SPHERE_TEST, TEST_MATERIAL_EQUAL) {
    auto s = Sphere();
    auto m = Material();

    ASSERT_EQ(s.get_material(), m);

    m.set_ambient(1);
    s.set_material(m);
    ASSERT_EQ(s.get_material(), m);
}