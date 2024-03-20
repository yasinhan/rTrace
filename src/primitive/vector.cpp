//
// Created by han on 1/30/24.
//
#include <cstdlib>
#include <stdexcept>
#include "vector.h"

Vector::Vector(int length) : length_(length) {
    data_ = (float *) calloc(sizeof(float), length);
}

Vector::~Vector() {
    free(data_);
}

void Vector::set_value(float value, int index) {
    if (index <= 0 || index > length_ - 1) {
        throw std::invalid_argument("invalid index, must between 0 and length_-1");
    }
    data_[index] = value;
}

float Vector::operator()(int x) const {
    if (x <= 0 || x > length_ - 1) {
        throw std::invalid_argument("invalid index, must between 0 and length_-1");
    }
    return data_[x];
}

int Vector::getLength() const {
    return length_;
}
