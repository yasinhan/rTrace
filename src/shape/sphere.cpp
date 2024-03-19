//
// Created by han on 3/7/24.
//
#include "sphere.h"
#include <cmath>

Sphere::Sphere() {
    origin = Tuple::point(0, 0, 0);
}

Intersections Sphere::intersect(const Ray& ray) const {
    auto actual_ray = ray;
    if (has_trans) {
        actual_ray = ray.transform(inverse_trans);
    }

    auto sphere_to_ray = actual_ray.getOrigin() - this->origin;
    auto a = actual_ray.getDirection().self_dot();
    auto b = 2 * actual_ray.getDirection().dot(sphere_to_ray);
    auto c = sphere_to_ray.self_dot() - 1;

    auto discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return Intersections(std::vector<Intersection>());
    }
    auto sqrt_dis = (float) sqrt(discriminant);
    float t1 = (-b - sqrt_dis) / (2 * a);
    float t2 = (-b + sqrt_dis) / (2 * a);

    return Intersections(std::vector<Intersection>{Intersection(t1, this), Intersection(t2, this)});
}

void Sphere::set_transform(const Matrix &transform) {
    trans = transform;
    inverse_trans = trans.inverse();
    has_trans = true;
}

Tuple Sphere::normal_at(const Tuple &point) const {
    if (!has_trans) {
        return (point - this->origin).normalized();
    }
    auto object_normal = inverse_trans * point - origin;
    auto world_normal = inverse_trans.transpose() * object_normal;
    world_normal.setW(0);
    return world_normal.normalized();
}
