//
// Created by han on 3/7/24.
//

#ifndef RAY_TRACE_SPHERE_H
#define RAY_TRACE_SPHERE_H

#include "../primitive/tuple.h"
#include "../primitive/ray.h"
#include "../primitive/intersections.h"


class Sphere {

public:
    Sphere();

    ~Sphere() = default;

    [[nodiscard]] Intersections intersect(const Ray& ray) const;

private:
    Tuple origin;
};

#endif //RAY_TRACE_SPHERE_H
