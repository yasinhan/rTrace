//
// Created by han on 4/15/24.
//

#include "pattern.h"

void Pattern::set_transform(const Matrix &transform) {
    trans_ = transform;
    inverse_trans = trans_.inverse();
    has_trans = true;
}

Color Pattern::color_at(const Tuple &point) const {
    if (has_trans) {
        auto actual_point = inverse_trans * point;
        return color_at_pattern(actual_point);
    }
    return color_at_pattern(point);
}


