//
// Created by han on 3/7/24.
//

#ifndef RAY_TRACE_SPHERE_H
#define RAY_TRACE_SPHERE_H

#include "../primitive/tuple.h"
#include "../primitive/ray.h"
#include "../primitive/intersections.h"
#include "material.h"

class Sphere {

public:
    Sphere();

    ~Sphere() = default;

    [[nodiscard]] Intersections intersect(const Ray& ray) const;

    void set_transform(const Matrix &transform);

    [[nodiscard]] Tuple normal_at(const Tuple &point) const;

    void set_material(const Material &material);

    const Material &get_material() const;

private:
    Tuple origin_;

    Matrix trans_ = Matrix::build_identity_matrix(4);

    Matrix inverse_trans = trans_;

    bool has_trans = false;

    Material material_ = Material();
};

#endif //RAY_TRACE_SPHERE_H
