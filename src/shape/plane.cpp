//
// Created by han on 4/9/24.
//

#include "plane.h"
#include "src/math.h"

Plane::Plane() {

}

Intersections Plane::intersect_with(const Ray &ray) const {
    if (std::abs(ray.get_direction().getY()) < EPSILON) {
        return Intersections(std::vector<Intersection>());
    }
    auto t = -ray.get_origin().getY() / ray.get_direction().getY();
    return Intersections(std::vector<Intersection>{Intersection(t, this)});
}

Tuple Plane::local_normal_at(const Tuple &point) const {
    return Tuple::vector(0, 1, 0);
}
