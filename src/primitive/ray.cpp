//
// Created by han on 3/7/24.
//

#include "ray.h"
#include <stdexcept>

Ray::Ray(const Tuple &origin, const Tuple &direction) : origin(origin), direction(direction) {
    if (!origin.isPoint()) {
        throw std::invalid_argument("origin must be point");
    }
    if (!direction.isVector()) {
        throw std::invalid_argument("direction must be vector");
    }
}

Ray::~Ray() {

}

Tuple Ray::position(float t) {
    return origin + direction * t;
}

const Tuple &Ray::getOrigin() const {
    return origin;
}

const Tuple &Ray::getDirection() const {
    return direction;
}
