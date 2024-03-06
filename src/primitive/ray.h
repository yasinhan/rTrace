//
// Created by han on 3/6/24.
//

#ifndef RAY_TRACE_RAY_H
#define RAY_TRACE_RAY_H

#include "tuple.h"
class Ray {

public:

    Ray(const Tuple &origin, const Tuple &direction) : origin(origin), direction(direction) {}

    virtual ~Ray() {

    }

    Tuple position(float t);

private:

    Tuple origin, direction;
};

#endif //RAY_TRACE_RAY_H
