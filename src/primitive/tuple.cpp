#include "tuple.h"
#include "src/math.h"
#include <stdexcept>
#include <cmath>
//
// Created by han on 12/22/23.
//
Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
    if (!epsilon(w, 0) && !epsilon(w, 1)) {
        throw std::invalid_argument("row must be 0 or 1");
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

Tuple Tuple::point(float x, float y, float z) {
    return {x, y, z, 1};
}

Tuple Tuple::vector(float x, float y, float z) {
    return {x, y, z, 0};
}

float Tuple::get_magnitude() const {
    return sqrtf(x * x + y * y + z * z);
}

// return a new tuple
Tuple Tuple::negate() const {
    return {-x , -y, -z, w};
}

Tuple Tuple::normalized() const {
    float length = get_magnitude();
    return {x / length, y / length, z / length, w};
}

float Tuple::dot(Tuple& other) const {
    if (isPoint() || other.isPoint()) {
        throw std::invalid_argument("Only two vector can dot");
    }
    return x * other.getX() + y * other.getY() + z * other.getZ();
}

Tuple Tuple::cross(Tuple& other) const {
    if (isPoint() || other.isPoint()) {
        throw std::invalid_argument("Only two vector can cross");
    }
    return {y * other.getZ() - z * other.getY(),
            z * other.getX() - x * other.getZ(),
            x * other.getY() - y * other.getX(),
            0};
}

bool Tuple::isPoint() const {
    return epsilon(w, 1);
}

bool Tuple::isVector() const {
    return epsilon(w, 0);
}


Tuple operator+(const Tuple &lhs, const Tuple &rhs) {
    if (lhs.isPoint() && rhs.isPoint()) {
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

Tuple operator*(const Tuple &lhs, float rhs) {
    if (lhs.isPoint()) {
        throw std::invalid_argument("Point cannot multiply");
    }
    return {lhs.getX() * rhs, lhs.getY() * rhs, lhs.getZ() * rhs, lhs.getW()};
}

Tuple operator/(const Tuple &lhs, float rhs) {
    if (lhs.isPoint()) {
        throw std::invalid_argument("Point cannot divide");
    }
    return {lhs.getX() / rhs, lhs.getY() / rhs, lhs.getZ() / rhs, lhs.getW()};
}