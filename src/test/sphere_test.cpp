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

    ASSERT_EQ(intersection.size(), 2);
    ASSERT_FLOAT_EQ(intersection[0].getT(), 4.0);
    ASSERT_FLOAT_EQ(intersection[1].getT(), 6.0);

    auto ray_1 = Ray(Tuple::point(0, 2, -5), Tuple::vector(0, 0, 1));
    auto intersection_1 = s.intersect(ray_1);
    ASSERT_EQ(intersection.size(), 0);
}
