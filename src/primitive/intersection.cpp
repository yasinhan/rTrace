//
// Created by han on 3/7/24.
//
#include "intersection.h"

Intersection::Intersection(float t, const void *obj) : t(t), obj(obj) {}

float Intersection::get_t() const {
    return t;
}

const void *Intersection::get_obj() const {
    return obj;
}

bool Intersection::operator==(Intersection other) const {
    return obj == other.get_obj() && t == other.get_t();
}



