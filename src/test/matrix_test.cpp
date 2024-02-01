//
// Created by han on 1/8/24.
//

#include "src/primitive/matrix.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(MATRIX_TEST, TEST_CREATE) {
    Matrix matrix = Matrix(3, 3);
    matrix.set_value(-3, 0, 0);
    matrix.set_value(5, 0, 1);
    matrix.set_value(1, 1, 0);
    matrix.set_value(-2, 1, 1);

    EXPECT_THROW(matrix.set_value(0, -1, -1), std::invalid_argument);

    ASSERT_FLOAT_EQ(matrix(0, 0), -3);
    ASSERT_FLOAT_EQ(matrix(0, 1), 5);
}

TEST(MATRIX_TEST, TEST_EQUAL) {
    auto matrix_1 = Matrix(2, 2);
    auto matrix_2 = Matrix(3, 3);

    ASSERT_FALSE(matrix_1 == matrix_2);

    matrix_1.set_value(0, 0, 0);
    matrix_1.set_value(0, 1, 0);
    matrix_1.set_value(0, 0, 1);
    matrix_1.set_value(0, 1, 1);

    auto matrix_3 = Matrix(2, 2);

    matrix_3.set_value(0, 0, 0);
    matrix_3.set_value(0, 1, 0);
    matrix_3.set_value(0, 0, 1);
    matrix_3.set_value(0, 1, 1);

    ASSERT_TRUE(matrix_1 == matrix_3);
}

TEST(MATRIX_TEST, TEST_MULTIPLY) {
    auto matrix_0 = Matrix(1, 1);
    auto matrix_1 = Matrix(2, 1);

    EXPECT_THROW(matrix_0 * matrix_1, std::invalid_argument);

    auto matrix_2 = Matrix(3, 2);
    matrix_2.set_value(1, 0, 0);
    matrix_2.set_value(2, 0, 1);
    matrix_2.set_value(1, 1, 0);
    matrix_2.set_value(2, 1, 1);
    matrix_2.set_value(1, 2, 0);
    matrix_2.set_value(2, 2, 1);

    auto matrix_3 = Matrix(2, 3);
    matrix_3.set_value(1, 0, 0);
    matrix_3.set_value(2, 0, 1);
    matrix_3.set_value(3, 0, 2);
    matrix_3.set_value(2, 1, 0);
    matrix_3.set_value(4, 1, 1);
    matrix_3.set_value(6, 1, 2);

    auto ret = matrix_2 * matrix_3;

    ASSERT_EQ(ret.getRow(), 3);
    ASSERT_EQ(ret.getCol(), 3);

    ASSERT_FLOAT_EQ(ret(0, 0), 5);
    ASSERT_FLOAT_EQ(ret(0, 1), 10);
    ASSERT_FLOAT_EQ(ret(0, 2), 15);

}

TEST(MATRIX_TEST, TEST_TRANSPOSE) {
    auto matrix = Matrix(3, 2);
    matrix.set_value(1, 0, 0);
    matrix.set_value(2, 0, 1);
    matrix.set_value(1, 1, 0);
    matrix.set_value(2, 1, 1);
    matrix.set_value(1, 2, 0);
    matrix.set_value(2, 2, 1);

    auto matrix_t = matrix.transpose();
    ASSERT_EQ(matrix_t.getRow(), 2);
    ASSERT_EQ(matrix_t.getCol(), 3);
    ASSERT_FLOAT_EQ(matrix_t(0, 0), 1);
    ASSERT_FLOAT_EQ(matrix_t(0, 1), 1);
    ASSERT_FLOAT_EQ(matrix_t(0, 2), 1);
    ASSERT_FLOAT_EQ(matrix_t(1, 0), 2);
}