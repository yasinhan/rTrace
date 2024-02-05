//
// Created by han on 1/18/24.
//

#include <cstdlib>
#include <stdexcept>
#include "matrix.h"
#include "matrix_sub.h"
#include "src/math.h"

Matrix::Matrix(int row, int col) {
    this->row = row;
    this->col = col;
    data = (float *) calloc(sizeof(float), row * col);
}

Matrix::~Matrix() {
    free(data);
}

int Matrix::get_index(int x, int y) const {
    if (x < 0 || y < 0) {
        throw std::invalid_argument("x cannot smaller than 0, y cannot smaller than 0");
    }
    if (x >= row || y >= col) {
        throw std::invalid_argument("x cannot bigger than row, y cannot bigger than col");
    }
    return x * col + y;
}

void Matrix::set_value(float value, int x, int y) {
    int index = get_index(x, y);
    data[index] = value;
}

float Matrix::operator()(int x, int y) const {
    return data[get_index(x, y)];
}

int Matrix::getRow() const {
    return row;
}

int Matrix::getCol() const {
    return col;
}

Matrix Matrix::build_identity_matrix(int w) {
    return Matrix(0, 0);
}

Matrix Matrix::transpose() const {
    auto ret = Matrix(this->col, this->row);

    for (int i = 0; i < ret.getRow(); i++) {
        for (int j = 0; j < ret.getCol(); j++) {
            ret.set_value(operator()(j, i), i, j);
        }
    }
    return ret;
}

Matrix Matrix::sub_matrix(int row, int col) const {
    if (this->row <= 1 || this->col <= 1) {
        throw std::invalid_argument("Matrix with 1 row or 1 column have no SubMatrix");
    }
    auto ret = Matrix(this->row - 1, this->col - 1);
    for (int i = 0; i < this->row; i++) {
        if (i == row) {
            continue;
        }
        int i_index = i > row ? i - 1 : i;
        for (int j = 0; j < this->col; j++) {
            if (j == col) {
                continue;
            }
            int j_index = j > col ? j - 1 : j;
            ret.set_value(operator()(i, j), i_index, j_index);
        }
    }
    return ret;
}

float Matrix::determinant() const {
    if (row == 2 && col == 2) {
        return operator()(0, 0) * operator()(1, 1) - operator()(0, 1) * operator()(1, 0);
    }
    float result = 0;
    for (int i = 0; i < col; i++) {
        auto sub = MatrixSub(*this, nullptr, row - 1, col - 1, 0, i);
        result += operator()(0, i) * sub.cofactor();
    }
    return result;
}

bool operator==(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.getRow() != rhs.getRow() || lhs.getCol() != rhs.getCol()) {
        return false;
    }
    for (int row = 0; row < lhs.getRow(); row++) {
        for (int col = 0; col < lhs.getCol(); col++) {
            float l = lhs(row, col);
            float r = rhs(row, col);
            if (!epsilon(l, r)) {
                return false;
            }
        }
    }
    return true;
}

Vector operator*(const Matrix &lhs, const Vector &rhs) {
    if (lhs.getCol() != rhs.getLength()) {
        throw std::invalid_argument("Matrix A with n columns, Vector B must have n elements");
    }
    auto ret = Vector(lhs.getCol());
    for (int i = 0; i < rhs.getLength(); i++) {
        float element = 0;
        for (int j = 0; j < lhs.getRow(); j++) {
            element += lhs(i, j) * rhs(i);
        }
        ret.set_value(element, i);
    }
    return ret;
}

float calculate_matrix_value(const Matrix &left, const Matrix &right, int row, int col) {
    float result = 0;
    for (int i = 0; i < left.getCol(); i++) {
        result += left(row, i) * right(i, col);
    }
    return result;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.getCol() != rhs.getRow()) {
        throw std::invalid_argument("Matrix A with n columns, Matrix B must have n rows");
    }
    auto ret = Matrix(lhs.getRow(), rhs.getCol());

    for (int i = 0; i < ret.getRow(); i++) {
        for (int j = 0; j < ret.getCol(); j++) {
            ret.set_value(calculate_matrix_value(lhs, rhs, i, j), i, j);
        }
    }
    return ret;
}