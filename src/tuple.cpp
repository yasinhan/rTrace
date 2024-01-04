#include "tuple.h"
#include "math.h"
#include <stdexcept>
#include <cmath>
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

std::unique_ptr<Tuple> Tuple::point(float x, float y, float z) {
    return std::make_unique<Tuple>(x, y, z, 1);
}

std::unique_ptr<Tuple> Tuple::vector(float x, float y, float z) {
    return std::make_unique<Tuple>(x, y, z, 0);
}

float Tuple::get_magnitude() const {
    return sqrtf(x * x + y * y + z * z);
}

// return a new tuple
std::unique_ptr<Tuple> Tuple::negate() const {
    return std::make_unique<Tuple>(-x , -y, -z, w);
}

std::unique_ptr<Tuple> Tuple::normalized() const {
    float length = get_magnitude();
    return std::make_unique<Tuple>(x / length, y / length, z / length, w);
}


Tuple operator+(const Tuple &lhs, const Tuple &rhs) {
    if (epsilon(lhs.getW(), 1) && epsilon(rhs.getW(), 1)) {
        throw std::invalid_argument("Two point cannot add");
    }
    return {lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY(), lhs.getZ() + rhs.getZ(), lhs.getW() + rhs.getW()};
}

Tuple operator-(const Tuple &lhs, const Tuple &rhs) {
    if (epsilon(lhs.getW(), 0) && epsilon(rhs.getW(), 1)) {
        throw std::invalid_argument("Vector cannot subtract Point");
    }
    return {lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY(), lhs.getZ() - rhs.getZ(), lhs.getW() - rhs.getW()};
}
