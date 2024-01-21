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

    ASSERT_FLOAT_EQ(matrix(0, 0), -3);
    ASSERT_FLOAT_EQ(matrix(0, 1), 5);
}
