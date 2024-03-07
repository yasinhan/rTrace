//
// Created by han on 3/7/24.
//
#include "intersections.h"

Intersections::Intersections(const std::vector<Intersection> &intersections) : intersections(intersections) {}

Intersection Intersections::operator[](int index) {
    return intersections[index];
}

size_t Intersections::size() {
    return intersections.size();
}

