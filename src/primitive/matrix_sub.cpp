//
// Created by han on 2/4/24.
//

#include "matrix_sub.h"
#include <tuple>
#include <stdexcept>

MatrixSub::MatrixSub(Matrix &origin, MatrixSub *parent, int row, int col, int remove_row, int remove_col) : origin(
        origin), parent(parent), row(row), col(col), remove_row(remove_row), remove_col(remove_col) {}

MatrixSub::~MatrixSub() {

}

float MatrixSub::determinant() {



    return 0;
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
