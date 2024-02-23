//
// Created by han on 2/22/24.
//
#include "transformation.h"
#include "math.h"

Matrix translation(float x, float y, float z) {
    auto ret = Matrix(4, 4);

    for (int i = 0; i < ret.getRow(); i++) {
        for (int j = 0; j < ret.getCol(); j++) {
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
    for (int i = 0; i < ret.getRow(); i++) {
        for (int j = 0; j < ret.getCol(); j++) {
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
