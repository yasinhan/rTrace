//
// Created by han on 12/22/23.
//

#include <gtest/gtest.h>
#include "src/primitive/tuple.h"
#include <cmath>

class RayTest : public ::testing::Test {
protected:
    RayTest() = default;
    ~RayTest() override = default;
};


TEST(TUPLE_TEST, CREATE_POINT_TEST) {
    auto point = std::make_unique<Tuple>(Tuple::point(4, -4, 3));

    EXPECT_EQ(point->getX(), 4);
    EXPECT_EQ(point->getY(), -4);
    EXPECT_EQ(point->getZ(), 3);
    EXPECT_EQ(point->getW(), 1);
}

TEST(TUPLE_TEST, CREATE_VECTOR_TEST) {
    auto vector = std::make_unique<Tuple>(Tuple::vector(4, -4, 3));

    EXPECT_EQ(vector->getX(), 4);
    EXPECT_EQ(vector->getY(), -4);
    EXPECT_EQ(vector->getZ(), 3);
    EXPECT_EQ(vector->getW(), 0);
}

TEST(TUPLE_TEST, ADD_TEST) {
    auto point = Tuple::point(1, 1, 1);
    auto vector = Tuple::vector(1, 1, 1);

    auto point_add_Vec = std::make_unique<Tuple>(point + vector);

    EXPECT_EQ(point_add_Vec->getW(), 1);
    EXPECT_EQ(point_add_Vec->getX(), 2);
    EXPECT_EQ(point_add_Vec->getY(), 2);
    EXPECT_EQ(point_add_Vec->getZ(), 2);
}

TEST(TUPLE_TEST, SUBTRACT_TEST) {
    auto point = Tuple::point(1, 1, 1);
    auto vector = Tuple::vector(1, 1, 1);

    auto point_subtract_vec = std::make_unique<Tuple>(point - vector);

    EXPECT_EQ(point_subtract_vec->getX(), 0);
    EXPECT_EQ(point_subtract_vec->getY(), 0);
    EXPECT_EQ(point_subtract_vec->getZ(), 0);
    EXPECT_EQ(point_subtract_vec->getW(), 1);
}

TEST(TUPLE_TEST, MULIPLY_TEST) {
    auto vector = Tuple::vector(1, 2, 3);

    auto new_vec = std::make_unique<Tuple>(vector * 4);

    EXPECT_EQ(new_vec->getX(), 4);
    EXPECT_EQ(new_vec->getY(), 8);
    EXPECT_EQ(new_vec->getZ(), 12);
}

TEST(TUPLE_TEST, DIVIDE_TEST) {
    auto vector = Tuple::vector(4, 8, 12);

    auto new_vec = std::make_unique<Tuple>(vector / 4);

    EXPECT_EQ(new_vec->getX(), 1);
    EXPECT_EQ(new_vec->getY(), 2);
    EXPECT_EQ(new_vec->getZ(), 3);
}

TEST(TUPLE_TEST, NEGATE_TEST) {
    auto tuple = new Tuple(1, -2, 3, 0);
    auto negative_tuple = std::make_unique<Tuple>(tuple->negate());

    EXPECT_EQ(negative_tuple->getX(), -1);
    EXPECT_EQ(negative_tuple->getY(), 2);
    EXPECT_EQ(negative_tuple->getZ(), -3);

    delete tuple;
}

TEST(TUPLE_TEST, NORMALIZED_TEST) {
    auto vector = Tuple::vector(1, 1, sqrtf(2));

    auto unit_vec = std::make_unique<Tuple>(vector.normalized());
    EXPECT_EQ(unit_vec->getX(), 0.5);
    EXPECT_EQ(unit_vec->getY(), 0.5);
    EXPECT_EQ(unit_vec->getZ(), sqrtf(2) / 2);

}

TEST(TUPLE_TEST, DOT_TEST) {
    auto vec_1 = Tuple::vector(1, -2, 3);
    auto vec_2 = Tuple::vector(2, -4, 6);

    auto dot_vec = vec_1.dot(vec_2);

    EXPECT_EQ(dot_vec, 28);
}

TEST(TUPLE_TEST, CROSS_TEST) {
    auto vec_1 = Tuple::vector(1, 2, 3);
    auto vec_2 = Tuple::vector(2, 3, 4);

    auto vec_1_cross_2 = std::make_unique<Tuple>(vec_1.cross(vec_2));
    EXPECT_EQ(vec_1_cross_2->getX(), -1);
    EXPECT_EQ(vec_1_cross_2->getY(), 2);
    EXPECT_EQ(vec_1_cross_2->getZ(), -1);

    auto vec_2_cross_1 = std::make_unique<Tuple>(vec_2.cross(vec_1));
    EXPECT_TRUE(vec_1_cross_2->negate().equals(*vec_2_cross_1));
}

TEST(TUPLE_TEST, EQUAL_TEST) {
    auto vec1 = Tuple::vector(1, 2, 3);
    auto vec2 = Tuple::vector(1, 2, 3);

    ASSERT_EQ(vec1, vec2);

    auto point_1 = Tuple::point(1, 2, 3);
    auto point_2 = Tuple::point(1, 2, 3);
    ASSERT_EQ(point_1, point_2);
}

TEST(TUPLE_TEST, REFLECT_TEST) {
    auto in = Tuple::vector(1, -1, 0);
    auto normal = Tuple::vector(0, 1, 0);

    auto ret = in.reflect(normal);
    ASSERT_EQ(ret, Tuple::vector(1, 1, 0));

    auto in_1 = Tuple::vector(0, -1, 0);
    auto normal_1 = Tuple::vector((float )sqrt(2) / 2, (float )sqrt(2) / 2, 0);

    auto ret_1 = in_1.reflect(normal_1);
    ASSERT_EQ(ret_1, Tuple::vector(1, 0, 0));
}

