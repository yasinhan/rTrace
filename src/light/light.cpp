//
// Created by han on 3/20/24.
//
#include "light.h"

Light::Light(const Color &intensity, const Tuple &position) : intensity_(intensity), position_(position) {}

const Color &Light::get_intensity() const {
    return intensity_;
}

const Tuple &Light::get_position() const {
    return position_;
}
