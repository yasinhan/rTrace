//
// Created by han on 3/26/24.
//

#include "shape.h"

void Shape::set_transform(const Matrix &transform) {
    trans_ = transform;
    inverse_trans = trans_.inverse();
    has_trans = true;
}

void Shape::set_material(const Material &material) {
    material_ = material;
}

const Material &Shape::get_material() const{
    return material_;
}

Intersections Shape::intersect(const Ray &ray) const {
    auto actual_ray = ray;
    if (has_trans) {
        actual_ray = ray.transform(inverse_trans);
    }
    return intersect_with(actual_ray);
}

Tuple Shape::normal_at(const Tuple &point) const {
    auto local_point = has_trans ? inverse_trans * point : point;
    auto local_normal = local_normal_at(local_point);

    auto world_normal = inverse_trans.transpose() * local_normal;
    world_normal.setW(0.0);
    return world_normal.normalized();
}
