//
// Created by han on 1/2/24.
//

#ifndef RAY_TRACE_MATH_H
#define RAY_TRACE_MATH_H

#include <cstdlib>

const float EPSILON = 0.00001 * 3;

inline bool epsilon(float a, float b) {
    return std::abs(a - b) < EPSILON;
}

#endif //RAY_TRACE_MATH_H
