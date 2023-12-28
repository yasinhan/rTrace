#include "tuple.h"
#include <stdexcept>

//
// Created by han on 12/22/23.
//
Tuple::Tuple(float x, float y, float z, int w) : x(x), y(y), z(z), w(w) {
    if (w != 0 && w != 1) {
        throw std::invalid_argument("w must be 0 or 1");
    }
}

Tuple::~Tuple() = default;

bool Tuple::equals(Tuple other) {
    return false;
}

float Tuple::getX() const {
    return x;
}

float Tuple::getY() const {
    return y;
}

float Tuple::getZ() const {
    return z;
}

int Tuple::getW() const {
    return w;
}

Tuple Tuple::vector(float x, float y, float z) {
    return {x, y, z, 1};
}

Tuple Tuple::point(float x, float y, float z) {
    return {x, y, z, 0};
}
