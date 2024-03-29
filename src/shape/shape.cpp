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

const Material &Shape::get_material() const {
    return material_;
}

Intersections Shape::intersect(const Ray &ray) const {
    return intersect_with(ray);
}

Tuple Shape::normal_at(const Tuple &point) const {
    return Tuple::vector(0, 0, 0);
}
