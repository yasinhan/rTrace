//
// Created by han on 1/18/24.
//

#include <cstdlib>
#include <stdexcept>
#include "matrix.h"
#include "src/math.h"

Matrix::Matrix(int w, int h) {
    this->w = w;
    this->h = h;
    data = (float *) calloc(sizeof(float), w * h);
}

Matrix::~Matrix() {
    free(data);
}

int Matrix::get_index(int x, int y) const {
    if (x >= w || y >= h) {
        throw std::invalid_argument("x cannot bigger than w, y cannot bigger than h");
    }
    return x * w + y;
}

void Matrix::set_value(float value, int x, int y) {
    int index = get_index(x, y);
    data[index] = value;
}

float Matrix::operator()(int x, int y) const {
    return data[get_index(x, y)];
}

int Matrix::getW() const {
    return w;
}

int Matrix::getH() const {
    return h;
}

bool operator==(const Matrix lhs, const Matrix rhs) {
    if (lhs.getW() != rhs.getW() || lhs.getH() != rhs.getH()) {
        return false;
    }
    for (int row = 0; row < lhs.getW(); row++) {
        for (int col = 0; col < lhs.getH(); col++) {
            float l = lhs(row, col);
            float r = rhs(row, col);
            if (!epsilon(l, r)) {
                return false;
            }
        }
    }
    return true;
}
