//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_MATRIX_H
#define RAY_TRACE_MATRIX_H

#include "vector.h"
#include "tuple.h"

class Matrix {

public:

    Matrix(int row, int col);

    virtual ~Matrix();

    float operator()(int x, int y) const;

    void set_value(float value, int x, int y);

    int get_row() const;

    int get_col() const;

    static Matrix build_identity_matrix(int w);

    Matrix transpose() const;

    Matrix sub_matrix(int row, int col) const;

    float determinant() const;

    Matrix inverse() const;

    Matrix& operator=(const Matrix& other);

    Matrix(const Matrix& other);

private:
    int row_, col_;
    float *data_;

    inline int get_index(int x, int y) const;

};

Matrix operator*(const Matrix &lhs, const Matrix &rhs);

Vector operator*(const Matrix &lhs, const Vector &rhs);

Tuple operator*(const Matrix &lhs, const Tuple &rhs);

bool operator==(const Matrix &lhs, const Matrix &rhs);

#endif //RAY_TRACE_MATRIX_H
