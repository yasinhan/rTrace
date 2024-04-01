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

TEST(TRANSFORMATION_TEST, TEST_VIEW_TRANSFORM_DEFAULT_ORIENTATION) {
    auto from = Tuple::point(0, 0, 0);
    auto to = Tuple::point(0, 0, -1);
    auto up = Tuple::vector(0, 1, 0);
    auto transform = view_transform(from, to, up);

    ASSERT_EQ(transform, Matrix::build_identity_matrix(4));
}

TEST(TRANSFORMATION_TEST, TEST_VIEW_TRANSFORM_LOOKING_IN_POSITIVE_Z) {
    auto from = Tuple::point(0, 0, 0);
    auto to = Tuple::point(0, 0, 1);
    auto up = Tuple::vector(0, 1, 0);
    auto transform = view_transform(from, to, up);

    ASSERT_EQ(transform, scaling(-1, 1, -1));
}

TEST(TRANSFORMATION_TEST, TEST_VIEW_TRANSFORM_MOVE_WORLD) {
    auto from = Tuple::point(0, 0, 8);
    auto to = Tuple::point(0, 0, 0);
    auto up = Tuple::vector(0, 1, 0);
    auto transform = view_transform(from, to, up);

    ASSERT_EQ(transform, translation(0, 0, -8));
}

TEST(TRANSFORMATION_TEST, TEST_VIEW_TRANSFORM_ARBITRARY_TRANSFORM) {
    auto from = Tuple::point(1, 3, 2);
    auto to = Tuple::point(4, -2, 8);
    auto up = Tuple::vector(1, 1, 0);
    auto transform = view_transform(from, to, up);

    auto ret = Matrix(4, 4);
    ret.set_value(-0.50709, 0,0);
    ret.set_value(0.50709, 0,1);
    ret.set_value(0.67612, 0, 2);
    ret.set_value(-2.36643, 0, 3);
    ret.set_value(0.76772, 1, 0);
    ret.set_value(0.60609, 1,1);
    ret.set_value(0.12122, 1, 2);
    ret.set_value(-2.82843, 1, 3);
    ret.set_value(-0.35857, 2, 0);
    ret.set_value(0.59761, 2, 1);
    ret.set_value(-0.71714, 2, 2);
    ret.set_value(0, 2, 3);
    ret.set_value(0, 3, 0);
    ret.set_value(0, 3, 1);
    ret.set_value(0, 3, 2);
    ret.set_value(1, 3, 3);
    ASSERT_EQ(transform, ret);
}