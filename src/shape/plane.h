//
// Created by han on 4/9/24.
//

#ifndef RAY_TRACE_PLANE_H
#define RAY_TRACE_PLANE_H


#include "shape.h"

class Plane : public Shape {
public:
    Plane();

    ~Plane() = default;

    [[nodiscard]] Intersections intersect_with(const Ray &ray) const override;

    [[nodiscard]] Tuple &local_normal_at(const Tuple &point) const override;

};


#endif //RAY_TRACE_PLANE_H
