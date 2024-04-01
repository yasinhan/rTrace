//
// Created by han on 2/22/24.
//
#include "transformation.h"
#include "math.h"

Matrix translation(float x, float y, float z) {
    auto ret = Matrix(4, 4);

    for (int i = 0; i < ret.get_row(); i++) {
        for (int j = 0; j < ret.get_col(); j++) {
            if (i == j) {
                ret.set_value(1, i, j);
            } else {
                ret.set_value(0, i, j);
            }
        }
    }
    ret.set_value(x, 0, 3);
    ret.set_value(y, 1, 3);
    ret.set_value(z, 2, 3);
    return ret;
}

Matrix scaling(float x, float y, float z) {
    auto ret = Matrix(4, 4);
    for (int i = 0; i < ret.get_row(); i++) {
        for (int j = 0; j < ret.get_col(); j++) {
            if (i != j) {
                ret.set_value(0, i, j);
            }
        }
    }
    ret.set_value(x, 0, 0);
    ret.set_value(y, 1, 1);
    ret.set_value(z, 2, 2);
    ret.set_value(1, 3, 3);
    return ret;
}

Matrix rotate_x(float radian) {
    float cos_r = cos(radian);
    float sin_r = sin(radian);

    auto ret = Matrix(4, 4);
    ret.set_value(1, 0, 0);
    ret.set_value(cos_r, 1, 1);
    ret.set_value(-sin_r, 1, 2);
    ret.set_value(sin_r, 2, 1);
    ret.set_value(cos_r, 2, 2);
    ret.set_value(1, 3, 3);
    return ret;
}

Matrix rotate_y(float radian) {
    float cos_r = cos(radian);
    float sin_r = sin(radian);

    auto ret = Matrix(4, 4);
    ret.set_value(cos_r, 0, 0);
    ret.set_value(sin_r, 0, 2);
    ret.set_value(1, 1, 1);
    ret.set_value(-sin_r, 2, 0);
    ret.set_value(cos_r, 2, 2);
    ret.set_value(1, 3, 3);
    return ret;
}

Matrix rotate_z(float radian) {
    float cos_r = cos(radian);
    float sin_r = sin(radian);

    auto ret = Matrix(4, 4);
    ret.set_value(cos_r, 0, 0);
    ret.set_value(-sin_r, 0, 1);
    ret.set_value(sin_r, 1, 0);
    ret.set_value(cos_r, 1, 1);
    ret.set_value(1, 2, 2);
    ret.set_value(1, 3, 3);
    return ret;
}

Matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y) {
    auto ret = Matrix(4, 4);
    ret.set_value(1, 0, 0);
    ret.set_value(x_y, 0, 1);
    ret.set_value(x_z, 0, 2);

    ret.set_value(y_x, 1, 0);
    ret.set_value(1, 1, 1);
    ret.set_value(y_z, 1, 2);

    ret.set_value(z_x, 2, 0);
    ret.set_value(z_y, 2, 1);
    ret.set_value(1, 2, 2);
    ret.set_value(1, 3, 3);
    return ret;
}

Matrix view_transform(Tuple &from, Tuple &to, Tuple &up) {
    auto forward = (to - from).normalized();
    auto up_normal = up.normalized();
    auto left = forward.cross(up_normal);
    auto true_up = left.cross(forward);

    auto orientation = Matrix(4, 4);
    orientation.set_value(left.getX(), 0, 0);
    orientation.set_value(left.getY(), 0, 1);
    orientation.set_value(left.getZ(), 0, 2);
    orientation.set_value(true_up.getX(), 1, 0);
    orientation.set_value(true_up.getY(), 1, 1);
    orientation.set_value(true_up.getZ(), 1, 2);
    orientation.set_value(-forward.getX(), 2, 0);
    orientation.set_value(-forward.getY(), 2, 1);
    orientation.set_value(-forward.getZ(), 2, 2);
    orientation.set_value(1, 3, 3);

    return orientation * translation(-from.getX(), -from.getY(), -from.getZ());
}
