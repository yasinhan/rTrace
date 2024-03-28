//
// Created by han on 3/28/24.
//

#include "prepare_computations.h"

PrepareComputations::PrepareComputations(Intersection hit, Intersections &intersections, Ray &ray) {
    this->t_ = hit.get_t();
    this->object_ = static_cast<const Shape *>(hit.get_obj());
    this->point = ray.position(t_);
    this->eye_vector = -ray.get_direction();
    this->normal_vector = object_->normal_at(this->point);

}

float PrepareComputations::get_t() const {
    return t_;
}

const Shape *PrepareComputations::get_object() const {
    return object_;
}

const Tuple &PrepareComputations::get_point() const {
    return point;
}

const Tuple &PrepareComputations::get_eye_vector() const {
    return eye_vector;
}

const Tuple &PrepareComputations::get_normal_vector() const {
    return normal_vector;
}
