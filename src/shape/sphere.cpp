//
// Created by han on 3/7/24.
//
#include "sphere.h"

Sphere::Sphere() {
    origin = Tuple::point(0, 0, 0);
}

Intersections Sphere::intersect(const Ray& ray) const {

    return Intersections(std::vector<Intersection>());
}



