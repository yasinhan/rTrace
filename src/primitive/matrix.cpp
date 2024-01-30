//
// Created by han on 1/18/24.
//

#include <cstdlib>
#include <stdexcept>
#include "matrix.h"
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
        throw std::invalid_argument("x cannot bigger than row, y cannot bigger than h");
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

Vector operator*(const Matrix &lhx, const Vector &rhs) {
    if (lhx.getCol() != rhs.getLength()) {
        throw std::invalid_argument("Matrix A with n columns, Vector B must have n elements");
    }
    auto ret = Vector(lhx.getCol());
    

}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.getCol() != rhs.getRow()) {
        throw std::invalid_argument("Matrix A with n columns, Matrix B must have n rows");
    }

    return Matrix(0, 0);
}
