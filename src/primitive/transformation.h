//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_TRANSFORMATION_H
#define RAY_TRACE_TRANSFORMATION_H

#include "matrix.h"

Matrix translation(float x, float y, float z);

Matrix scaling(float x, float y, float z);

Matrix rotate_x(float radian);

Matrix rotate_y(float radian);

Matrix rotate_z(float radian);
#endif //RAY_TRACE_TRANSFORMATION_H
