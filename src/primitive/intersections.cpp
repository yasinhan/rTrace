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
    for (auto i = intersections.begin();i != intersections.end(); ++i) {
        if ((*i).getT() < 0) {
            continue;
        }
        if (res == std::nullopt || res.value().getT() > (*i).getT()) {
            res = std::optional<Intersection>(*i);
        }
    }
    return res;
}

