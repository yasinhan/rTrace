//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_MATRIX_SUB_H
#define RAY_TRACE_MATRIX_SUB_H

#include "vector.h"
#include "matrix.h"
#include <tuple>

class MatrixSub {

public:

    MatrixSub(const Matrix &origin, MatrixSub *parent, int row, int col, int remove_row, int remove_col);

    virtual ~MatrixSub();

    MatrixSub sub(int remove_row, int remove_col);

    float operator()(int x, int y);

    float determinant();

    float minor();

    float cofactor();

private:
    Matrix &origin_;
    MatrixSub *parent_;
    int row_, col_, remove_row_, remove_col_;

    inline std::tuple<int, int> get_coordinate_in_parent(int x, int y) const;

};

#endif //RAY_TRACE_MATRIX_SUB_H
