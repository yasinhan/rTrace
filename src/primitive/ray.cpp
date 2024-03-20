//
// Created by han on 3/7/24.
//

#include "ray.h"
#include <stdexcept>

Ray::Ray(const Tuple &origin, const Tuple &direction) : origin_(origin), direction_(direction) {
    if (!origin.is_point()) {
        throw std::invalid_argument("origin_ must be point");
    }
    if (!direction.is_vector()) {
        throw std::invalid_argument("direction_ must be vector");
    }
}

Ray::~Ray() {

}

Tuple Ray::position(float t) {
    return origin_ + direction_ * t;
}

const Tuple &Ray::get_origin() const {
    return origin_;
}

const Tuple &Ray::get_direction() const {
    return direction_;
}

Ray Ray::transform(const Matrix &transform) const {
    return {transform * origin_, transform * direction_};
}
