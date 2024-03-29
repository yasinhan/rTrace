//
// Created by han on 3/26/24.
//

#ifndef RAY_TRACE_SHAPE_H
#define RAY_TRACE_SHAPE_H

#include "src//primitive/tuple.h"
#include "src//primitive/ray.h"
#include "src//primitive/intersections.h"
#include "material.h"

class Shape {

public:
    ~Shape() = default;

    void set_transform(const Matrix &transform);

    void set_material(const Material &material);

    Material &get_material();

    Intersections intersect(const Ray &ray) const;

    [[nodiscard]] virtual Tuple normal_at(const Tuple &point) const;

protected:

    virtual Intersections intersect_with(const Ray &ray) const = 0;

    Matrix trans_ = Matrix::build_identity_matrix(4);

    Matrix inverse_trans = trans_;

    bool has_trans = false;

    Material material_ = Material();

};


#endif //RAY_TRACE_SHAPE_H
