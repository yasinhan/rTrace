//
// Created by han on 4/9/24.
//

#include "plane.h"

Plane::Plane() {

}

Intersections Plane::intersect_with(const Ray &ray) const {
    return Intersections(std::vector<Intersection>());
}

Tuple &Plane::local_normal_at(const Tuple &point) const {
    return <#initializer#>;
}
