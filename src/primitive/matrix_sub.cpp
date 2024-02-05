//
// Created by han on 2/4/24.
//

#include "matrix_sub.h"
#include <tuple>
#include <stdexcept>

MatrixSub::MatrixSub(const Matrix &origin, MatrixSub *parent, int row, int col, int remove_row, int remove_col) : origin(
        const_cast<Matrix &>(origin)), parent(parent), row(row), col(col), remove_row(remove_row), remove_col(remove_col) {}

MatrixSub::~MatrixSub() {

}

float MatrixSub::minor() {
    return determinant();
}

float MatrixSub::cofactor() {
    int factor = (remove_col + remove_row) % 2 == 0 ? 1 : -1;
    return factor * minor();
}

float MatrixSub::determinant() {
    if (row == 2 && col == 2) {
        return operator()(0, 0) * operator()(1, 1) - operator()(0, 1) * operator()(1, 0);
    }
    float result = 0;
    for (int i = 0; i < col; i++) {
        auto sub = this->sub(0, i);
        result += operator()(0, i) * sub.cofactor();
    }
    return result;
}

float MatrixSub::operator()(int x, int y) {
    auto coordinate_parent = get_coordinate_in_parent(x, y);
    if (nullptr == parent) {
        return origin.operator()(std::get<0>(coordinate_parent), std::get<1>(coordinate_parent));
    }
    return parent->operator()(std::get<0>(coordinate_parent), std::get<1>(coordinate_parent));
}

std::tuple<int, int> MatrixSub::get_coordinate_in_parent(int x, int y) const {
    if (x < 0 || y < 0) {
        throw std::invalid_argument("x cannot smaller than 0, y cannot smaller than 0");
    }
    if (x >= row || y >= col) {
        throw std::invalid_argument("x cannot bigger than row, y cannot bigger than col");
    }
    int x_index = x < remove_row ? x : x + 1;
    int y_index = y < remove_col ? y : y + 1;
    return std::tuple<int, int>(x_index, y_index);
}

MatrixSub MatrixSub::sub(int remove_row, int remove_col) {
    if (remove_row >= row || remove_col >= col) {
        throw std::invalid_argument("Cannot remove row or column not existd");
    }
    return MatrixSub(this->origin, this, row - 1, col - 1, remove_row, remove_col);
}
