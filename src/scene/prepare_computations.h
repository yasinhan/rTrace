//
// Created by han on 3/28/24.
//

#ifndef RAY_TRACE_PREPARE_COMPUTATIONS_H
#define RAY_TRACE_PREPARE_COMPUTATIONS_H

#include "src/shape/shape.h"

class PrepareComputations {

public:
    PrepareComputations(Intersection hit, Intersections &intersections, Ray &ray);
    ~PrepareComputations() = default;

    float get_t() const;

    const Shape *get_object() const;

    const Tuple &get_point() const;

    const Tuple &get_eye_vector() const;

    const Tuple &get_normal_vector() const;

    bool is_inside() const;

private:
    float t_;
    const Shape *object_;
    Tuple point_, eye_vector_, normal_vector_;
    bool inside_;
};


#endif //RAY_TRACE_PREPARE_COMPUTATIONS_H
