//
// Created by han on 3/28/24.
//

#include "prepare_computations.h"
#include "src/math.h"

PrepareComputations::PrepareComputations(Intersection hit, Intersections &intersections, Ray &ray) {
    this->t_ = hit.get_t();
    this->object_ = static_cast<const Shape *>(hit.get_obj());
    this->point_ = ray.position(t_);
    this->eye_vector_ = -ray.get_direction();
    this->normal_vector_ = object_->normal_at(this->point_);
    auto dot = normal_vector_.dot(eye_vector_);
    if (dot < 0) {
        this->inside_ = true;
        this->normal_vector_ = -normal_vector_;
    } else {
        this->inside_ = false;
    }
    this->over_point_ = point_ + normal_vector_ * EPSILON;
    this->reflect_vector_ = ray.get_direction().reflect(normal_vector_);
}

float PrepareComputations::get_t() const {
    return t_;
}

const Shape *PrepareComputations::get_object() const {
    return object_;
}

const Tuple &PrepareComputations::get_point() const {
    return point_;
}

const Tuple &PrepareComputations::get_eye_vector() const {
    return eye_vector_;
}

const Tuple &PrepareComputations::get_normal_vector() const {
    return normal_vector_;
}

bool PrepareComputations::is_inside() const {
    return inside_;
}

const Tuple &PrepareComputations::get_over_point() const {
    return over_point_;
}

const Tuple &PrepareComputations::get_reflect_vector() const {
    return reflect_vector_;
}
