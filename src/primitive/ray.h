//
// Created by han on 3/6/24.
//

#ifndef RAY_TRACE_RAY_H
#define RAY_TRACE_RAY_H

#include "tuple.h"
class Ray {

public:

    Ray(const Tuple &origin, const Tuple &direction);

    virtual ~Ray();

    [[nodiscard]] const Tuple &getOrigin() const;

    [[nodiscard]] const Tuple &getDirection() const;

    Tuple position(float t);

private:

    Tuple origin, direction;
};

#endif //RAY_TRACE_RAY_H
