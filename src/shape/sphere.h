//
// Created by han on 3/7/24.
//

#ifndef RAY_TRACE_SPHERE_H
#define RAY_TRACE_SPHERE_H

#include "src//primitive/tuple.h"
#include "src//primitive/ray.h"
#include "src//primitive/intersections.h"
#include "material.h"
#include "shape.h"

class Sphere : public Shape {

public:
    Sphere();

    ~Sphere() = default;

    Intersections intersect(const Ray &ray) const override;

    [[nodiscard]] Tuple normal_at(const Tuple &point) const override;

private:
    Tuple origin_;
};

#endif //RAY_TRACE_SPHERE_H
