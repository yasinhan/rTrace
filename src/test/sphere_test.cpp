//
// Created by han on 1/8/24.
//

#include <gtest/gtest.h>
#include "src/shape/sphere.h"

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
    ASSERT_FLOAT_EQ(intersection[0].getT(), 4.0);
    ASSERT_FLOAT_EQ(intersection[1].getT(), 6.0);
    ASSERT_EQ(intersection[0].getObj(), &s);

    auto ray_1 = Ray(Tuple::point(0, 2, -5), Tuple::vector(0, 0, 1));
    auto intersection_1 = s.intersect(ray_1);
    ASSERT_EQ(intersection_1.count(), 0);

    auto ray_2 = Ray(Tuple::point(0, 1, -5), Tuple::vector(0, 0, 1));
    auto intersection_2 = s.intersect(ray_2);
    ASSERT_EQ(intersection_2.count(), 2);
    ASSERT_FLOAT_EQ(intersection_2[0].getT(), 5.0);
    ASSERT_FLOAT_EQ(intersection_2[1].getT(), 5.0);

    auto ray_3 = Ray(Tuple::point(0, 0, 0), Tuple::vector(0, 0, 1));
    auto intersection_3 = s.intersect(ray_3);
    ASSERT_EQ(intersection_3.count(), 2);
    ASSERT_FLOAT_EQ(intersection_3[0].getT(), -1.0);
    ASSERT_FLOAT_EQ(intersection_3[1].getT(), 1.0);
}
