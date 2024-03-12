//
// Created by han on 3/7/24.
//
#include "intersection.h"

Intersection::Intersection(float t, const void *obj) : t(t), obj(obj) {}

float Intersection::getT() const {
    return t;
}

const void *Intersection::getObj() const {
    return obj;
}



