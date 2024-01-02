#include "tuple.h"
#include "math.h"
#include <stdexcept>

//
// Created by han on 12/22/23.
//
Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
    if (!epsilon(w, 0) && !epsilon(w, 1)) {
        throw std::invalid_argument("w must be 0 or 1");
    }
}

Tuple::~Tuple() = default;

bool Tuple::equals(const Tuple& other) {
    if (!epsilon(this->w, other.w)) {
        return false;
    }
    return epsilon(this->x, other.x) && epsilon(this->y, other.y) && epsilon(this->z, other.z);
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

float Tuple::getW() const {
    return w;
}

Tuple Tuple::vector(float x, float y, float z) {
    return {x, y, z, 1};
}

Tuple Tuple::point(float x, float y, float z) {
    return {x, y, z, 0};
}


Tuple operator+(const Tuple &lhs, const Tuple &rhs) {
    if (epsilon(lhs.getW(), 1) && epsilon(rhs.getW(), 1)) {
        throw std::invalid_argument("Two point cannot add");
    }
    return {lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY(), lhs.getZ() + rhs.getZ(), lhs.getW() + rhs.getW()};
}
