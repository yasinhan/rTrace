//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_MATRIX_H
#define RAY_TRACE_MATRIX_H

#include "vector.h"

class Matrix {

public:

    Matrix(int row, int col);

    virtual ~Matrix();

    float operator()(int x, int y) const;

    void set_value(float value, int x, int y);

    int getRow() const;

    int getCol() const;

    static Matrix build_identity_matrix(int w);

    Matrix transpose() const;

private:
    int row, col;
    float *data;

    inline int get_index(int x, int y) const;

};

Matrix operator*(const Matrix &lhs, const Matrix &rhs);

Vector operator*(const Matrix &lhs, const Vector &rhs);

bool operator==(const Matrix &lhs, const Matrix &rhs);

#endif //RAY_TRACE_MATRIX_H
