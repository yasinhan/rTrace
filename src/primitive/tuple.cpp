#include "tuple.h"
#include "src/math.h"
#include <stdexcept>
#include <cmath>
//
// Created by han on 12/22/23.
//
Tuple::Tuple(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) {
}

Tuple::~Tuple() = default;

bool Tuple::equals(const Tuple& other) {
    if (!epsilon(this->w_, other.w_)) {
        return false;
    }
    return epsilon(this->x_, other.x_) && epsilon(this->y_, other.y_) && epsilon(this->z_, other.z_);
}

float Tuple::getX() const {
    return x_;
}

float Tuple::getY() const {
    return y_;
}

float Tuple::getZ() const {
    return z_;
}

float Tuple::getW() const {
    return w_;
}

Tuple Tuple::point(float x, float y, float z) {
    return {x, y, z, 1};
}

Tuple Tuple::vector(float x, float y, float z) {
    return {x, y, z, 0};
}

float Tuple::get_magnitude() const {
    return sqrtf(x_ * x_ + y_ * y_ + z_ * z_);
}

// return a new tuple
Tuple Tuple::negate() const {
    return {-x_ , -y_, -z_, -w_};
}

Tuple Tuple::normalized() const {
    float length = get_magnitude();
    return {x_ / length, y_ / length, z_ / length, w_};
}

float Tuple::dot(const Tuple& other) const {
    if (is_point() || other.is_point()) {
        throw std::invalid_argument("Only two vector can dot");
    }
    return x_ * other.getX() + y_ * other.getY() + z_ * other.getZ();
}

float Tuple::self_dot() const {
    if (is_point()) {
        throw std::invalid_argument("Only vector can dot self");
    }
    return x_ * x_ + y_ * y_ + z_ * z_;
}

Tuple Tuple::cross(Tuple& other) const {
    if (is_point() || other.is_point()) {
        throw std::invalid_argument("Only two vector can cross");
    }
    return {y_ * other.getZ() - z_ * other.getY(),
            z_ * other.getX() - x_ * other.getZ(),
            x_ * other.getY() - y_ * other.getX(),
            0};
}

bool Tuple::is_point() const {
    return epsilon(w_, 1);
}

bool Tuple::is_vector() const {
    return epsilon(w_, 0);
}

void Tuple::setW(const float w) {
    this->w_ = w;
}

Tuple Tuple::reflect(const Tuple &in) const {
    return *this - in * (*this).dot(in) * 2;
}

bool operator==(const Tuple &lhs, const Tuple &rhs) {
    return epsilon(lhs.getX(), rhs.getX()) && epsilon(lhs.getY(), rhs.getY())
           && epsilon(lhs.getZ(), rhs.getZ()) && epsilon(lhs.getW(), rhs.getW());
}

Tuple operator+(const Tuple &lhs, const Tuple &rhs) {
    if (lhs.is_point() && rhs.is_point()) {
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
    if (lhs.is_point()) {
        throw std::invalid_argument("Point cannot multiply");
    }
    return {lhs.getX() * rhs, lhs.getY() * rhs, lhs.getZ() * rhs, lhs.getW()};
}

Tuple operator/(const Tuple &lhs, float rhs) {
    if (lhs.is_point()) {
        throw std::invalid_argument("Point cannot divide");
    }
    return {lhs.getX() / rhs, lhs.getY() / rhs, lhs.getZ() / rhs, lhs.getW()};
}

Tuple operator-(const Tuple &origin) {
    return {-origin.getX(), -origin.getY(), -origin.getZ(), -origin.getW()};

}
