//
// Created by han on 12/22/23.
//

#include <gtest/gtest.h>
#include "src/primitive/transformation.h"
#include <cmath>

TEST(TRANSFORMATION_TEST, TRANSLATION_TEST) {
    auto transform = translation(5, -3, 2);
    auto point = Tuple::point(-3, 4, 5);

    auto ret = transform * point;
    ASSERT_EQ(ret, Tuple::point(2, 1, 7));

    auto inverse_transform = transform.inverse();
    auto inverse_ret = inverse_transform * point;
    ASSERT_EQ(inverse_ret, Tuple::point(-8, 7, 3));

    auto vector = Tuple::vector(-3, 4, 5);
    auto vec_ret = transform * vector;
    ASSERT_EQ(vec_ret, Tuple::vector(-3, 4, 5));
}

TEST(TRANSFORMATION_TEST, SCALING_TEST) {
    auto transform = scaling(2, 3, 4);
    auto point = Tuple::point(-4, 6, 8);

    auto point_ret = transform * point;
    ASSERT_EQ(point_ret, Tuple::point(-8, 18, 32));

    auto vector = Tuple::vector(-4, 6, 8);

    auto vec_ret = transform * vector;
    ASSERT_EQ(vec_ret, Tuple::vector(-8, 18, 32));

    auto inverse_transform = transform.inverse();
    auto inverse_ret = inverse_transform * point;
    ASSERT_EQ(inverse_ret, Tuple::point(-2, 2, 2));

    auto transform_2 = scaling(-1, 1, 1);
    auto negative_ret = transform_2 * point;
    ASSERT_EQ(negative_ret, Tuple::point(4, 6, 8));
}

TEST(TRANSFORMATION_TEST, ROTATION_X_TEST) {
    auto transform = rotate_x(M_PI / 4);

    auto point = Tuple::point(0, 1, 0);
    auto ret = transform * point;

    ASSERT_EQ(ret, Tuple::point(0, sqrt(2) / 2, sqrt(2) / 2));

    auto transform_2 = rotate_x(M_PI / 2);
    auto ret_2 = transform_2 * point;
    ASSERT_EQ(ret_2, Tuple::point(0, 0, 1));

    auto inverse_trans_1 = transform.inverse();
    auto inverse_ret_1 = inverse_trans_1 * point;
    ASSERT_EQ(inverse_ret_1, Tuple::point(0, sqrt(2) / 2, -sqrt(2) / 2));
}

TEST(TRANSFORMATION_TEST, TEST_ROTATION_Y) {
    auto transform = rotate_y(M_PI / 4);
    auto point = Tuple::point(0, 0, 1);
    auto ret = transform * point;

    ASSERT_EQ(ret, Tuple::point( sqrt(2) / 2, 0, sqrt(2) / 2));

    auto transform_2 = rotate_y(M_PI / 2);
    auto ret_2 = transform_2 * point;
    ASSERT_EQ(ret_2, Tuple::point(1, 0, 0));
}

TEST(TRANSFORMATION_TEST, TEST_ROTATION_Z) {
    auto transform = rotate_z(M_PI / 4);
    auto point = Tuple::point(0, 1, 0);
    auto ret = transform * point;

    ASSERT_EQ(ret, Tuple::point( -sqrt(2) / 2, sqrt(2) / 2, 0));

    auto transform_2 = rotate_z(M_PI / 2);
    auto ret_2 = transform_2 * point;
    ASSERT_EQ(ret_2, Tuple::point(-1, 0, 0));
}

TEST(TRANSFORMATION_TEST, TEST_SHEARING_X_Y) {
    auto transform = shearing(1, 0, 0, 0, 0, 0);

    auto point = Tuple::point(2, 3, 4);
    auto ret = transform * point;
    ASSERT_EQ(ret, Tuple::point(5, 3, 4));
}

TEST(TRANSFORMATION_TEST, TEST_SHEARING_X_Z) {
    auto transform = shearing(0, 1, 0, 0, 0, 0);

    auto point = Tuple::point(2, 3, 4);
    auto ret = transform * point;
    ASSERT_EQ(ret, Tuple::point(6, 3, 4));
}

TEST(TRANSFORMATION_TEST, TEST_SHEARING_Y_X) {
    auto transform = shearing(0, 0, 1, 0, 0, 0);

    auto point = Tuple::point(2, 3, 4);
    auto ret = transform * point;
    ASSERT_EQ(ret, Tuple::point(2, 5, 4));
}

TEST(TRANSFORMATION_TEST, TEST_SHEARING_Y_Z) {
    auto transform = shearing(0, 0, 0, 1, 0, 0);

    auto point = Tuple::point(2, 3, 4);
    auto ret = transform * point;
    ASSERT_EQ(ret, Tuple::point(2, 7, 4));
}

TEST(TRANSFORMATION_TEST, TEST_SHEARING_Z_X) {
    auto transform = shearing(0, 0, 0, 0, 1, 0);

    auto point = Tuple::point(2, 3, 4);
    auto ret = transform * point;
    ASSERT_EQ(ret, Tuple::point(2, 3, 6));
}

TEST(TRANSFORMATION_TEST, TEST_SHEARING_Z_Y) {
    auto transform = shearing(0, 0, 0, 0, 0, 1);

    auto point = Tuple::point(2, 3, 4);
    auto ret = transform * point;
    ASSERT_EQ(ret, Tuple::point(2, 3, 7));
}

TEST(TRANSFORMATION_TEST, TEST_CHAINED) {
    auto a = rotate_x(M_PI / 2);
    auto b = scaling(5, 5, 5);
    auto c = translation(10, 5, 7);

    auto point = Tuple::point(1, 0, 1);
    auto mid_1 = a * point;
    auto mid_2 = b * mid_1;
    auto ret_1 = c * mid_2;

    ASSERT_EQ(ret_1, Tuple::point(15, 0, 7));

    auto matrix = c * b * a;
    auto ret_2 = matrix * point;
    ASSERT_EQ(ret_2, ret_1);
}