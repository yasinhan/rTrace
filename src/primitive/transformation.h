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

Matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);
#endif //RAY_TRACE_TRANSFORMATION_H
