//
// Created by han on 3/7/24.
//
#include "sphere.h"
#include <cmath>

Sphere::Sphere() {
    origin = Tuple::point(0, 0, 0);
}

Intersections Sphere::intersect(const Ray& ray) const {
    auto sphere_to_ray = ray.getOrigin() - this->origin;
    auto a = ray.getDirection().self_dot();
    auto b = 2 * ray.getDirection().dot(sphere_to_ray);
    auto c = sphere_to_ray.self_dot() - 1;

    auto discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return Intersections(std::vector<Intersection>());
    }
    float sqrt_dis = (float) sqrt(discriminant);
    float t1 = (-b - sqrt_dis) / (2 * a);
    float t2 = (-b + sqrt_dis) / (2 * a);

    return Intersections(std::vector<Intersection>{Intersection(t1), Intersection(t2)});
}
