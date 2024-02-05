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

TEST(MATRIX_TEST, TEST_SUB_MATRIX) {
    auto matrix = Matrix(3, 2);
    matrix.set_value(1, 0, 0);
    matrix.set_value(2, 0, 1);
    matrix.set_value(1, 1, 0);
    matrix.set_value(2, 1, 1);
    matrix.set_value(1, 2, 0);
    matrix.set_value(2, 2, 1);

    auto sub_matrix = matrix.sub_matrix(0, 1);

    ASSERT_EQ(sub_matrix.getRow(), 2);
    ASSERT_EQ(sub_matrix.getCol(), 1);

    ASSERT_FLOAT_EQ(sub_matrix(0, 0), 1);
    ASSERT_FLOAT_EQ(sub_matrix(1, 0), 1);

    EXPECT_THROW(sub_matrix.sub_matrix(0, 1), std::invalid_argument);
}

TEST(MATRIX_TEST, TEST_DETERMINANT) {
    auto matrix_1 = Matrix(2, 2);

    matrix_1.set_value(0, 0, 0);
    matrix_1.set_value(0, 1, 0);
    matrix_1.set_value(0, 0, 1);
    matrix_1.set_value(0, 1, 1);

    ASSERT_FLOAT_EQ(matrix_1.determinant(), 0);

    matrix_1.set_value(1, 0, 0);
    matrix_1.set_value(2, 1, 0);
    matrix_1.set_value(3, 0, 1);
    matrix_1.set_value(4, 1, 1);

    ASSERT_FLOAT_EQ(matrix_1.determinant(), -2);

    auto matrix_2 = Matrix(3, 3);
    matrix_2.set_value(1, 0, 0);
    matrix_2.set_value(2, 0, 1);
    matrix_2.set_value(6, 0, 2);
    matrix_2.set_value(-5, 1, 0);
    matrix_2.set_value(8, 1, 1);
    matrix_2.set_value(-4, 1, 2);
    matrix_2.set_value(2, 2, 0);
    matrix_2.set_value(6, 2, 1);
    matrix_2.set_value(4, 2, 2);

    ASSERT_FLOAT_EQ(matrix_2.determinant(), -196);

    auto matrix_3 = Matrix(4, 4);
    matrix_3.set_value(-2, 0,0);
    matrix_3.set_value(-8, 0,1);
    matrix_3.set_value(3, 0, 2);
    matrix_3.set_value(5, 0, 3);
    matrix_3.set_value(-3, 1, 0);
    matrix_3.set_value(1, 1,1);
    matrix_3.set_value(7, 1, 2);
    matrix_3.set_value(3, 1, 3);
    matrix_3.set_value(1, 2, 0);
    matrix_3.set_value(2, 2, 1);
    matrix_3.set_value(-9, 2, 2);
    matrix_3.set_value(6, 2, 3);
    matrix_3.set_value(-6, 3, 0);
    matrix_3.set_value(7, 3, 1);
    matrix_3.set_value(7, 3, 2);
    matrix_3.set_value(-9, 3, 3);

    ASSERT_FLOAT_EQ(matrix_3.determinant(), -4071);
}