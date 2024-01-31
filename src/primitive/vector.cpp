//
// Created by han on 1/30/24.
//
#include <cstdlib>
#include <stdexcept>
#include "vector.h"

Vector::Vector(int length) : length(length) {
    data = (float *) calloc(sizeof(float), length);
}

Vector::~Vector() {
    free(data);
}

void Vector::set_value(float value, int index) {
    if (index <= 0 || index > length - 1) {
        throw std::invalid_argument("invalid index, must between 0 and length-1");
    }
    data[index] = value;
}

float Vector::operator()(int x) const {
    if (x <= 0 || x > length - 1) {
        throw std::invalid_argument("invalid index, must between 0 and length-1");
    }
    return data[x];
}

int Vector::getLength() const {
    return length;
}
