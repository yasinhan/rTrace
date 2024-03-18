//
// Created by han on 1/8/24.
//

#include <gtest/gtest.h>
#include "src/primitive/intersection.h"
#include "src/shape/sphere.h"

class IntersectionTest : public ::testing::Test {
protected:
    IntersectionTest() = default;
    ~IntersectionTest() override = default;
};

TEST(INTERSECTION_TEST, TEST_HIT_POSITIVE) {
    auto s = Sphere();

    auto i1 = Intersection(1, &s);
    auto i2 = Intersection(2, &s);

    auto intersections = Intersections(std::vector<Intersection>{i1, i2});
    auto ret = intersections.hit();

    ASSERT_TRUE(ret.has_value());
    ASSERT_EQ(ret.value(), i1);
}

TEST(INTERSECTION_TEST, TEST_HIT_WITH_NEGATIVE) {
    auto s = Sphere();
    auto i1 = Intersection(-1, &s);
    auto i2 = Intersection(1, &s);

    auto intersections = Intersections(std::vector<Intersection>{i1, i2});
    auto ret = intersections.hit();

    ASSERT_TRUE(ret.has_value());
    ASSERT_EQ(ret.value(), i2);
}

TEST(INTERSECTION_TEST, TEST_HIT_ALL_NEGATIVE) {
    auto s = Sphere();
    auto i1 = Intersection(-1, &s);
    auto i2 = Intersection(-2, &s);

    auto intersections = Intersections(std::vector<Intersection>{i1, i2});
    auto ret = intersections.hit();

    ASSERT_FALSE(ret.has_value());
}

TEST(INTERSECTION_TEST, TEST_HIT_WITH_MULTI_INTER) {
    auto s = Sphere();
    auto i1 = Intersection(5, &s);
    auto i2 = Intersection(7, &s);
    auto i3 = Intersection(-3, &s);
    auto i4 = Intersection(2, &s);


    auto intersections = Intersections(std::vector<Intersection>{i1, i2, i3, i4});
    auto ret = intersections.hit();

    ASSERT_TRUE(ret.has_value());
    ASSERT_EQ(ret.value(), i4);
}