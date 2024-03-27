//
// Created by han on 3/7/24.
//
#include "intersections.h"

Intersections::Intersections(const std::vector<Intersection> &intersections) : intersections(intersections) {}

Intersection Intersections::operator[](int index) {
    return intersections[index];
}

size_t Intersections::count() {
    return intersections.size();
}

std::optional<Intersection> Intersections::hit() const {
    if (intersections.empty()) {
        return std::nullopt;
    }
    std::optional<Intersection> res = std::nullopt;
    for (auto intersection : intersections) {
        if (intersection.get_t() < 0) {
            continue;
        }
        if (res == std::nullopt || res.value().get_t() > intersection.get_t()) {
            res = std::optional<Intersection>(intersection);
        }
    }
    return res;
}

