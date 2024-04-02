//
// Created by han on 4/2/24.
//

#include "camera.h"

Camera::Camera(int h_size, int v_size, float field_of_view) : h_size_(h_size), v_size_(v_size), field_of_view_(field_of_view) {}

int Camera::get_h_size() const {
    return h_size_;
}

int Camera::get_v_size() const {
    return v_size_;
}

float Camera::get_field_of_view() const {
    return field_of_view_;
}

const Matrix &Camera::get_transform() const {
    return transform_;
}

void Camera::set_transform(const Matrix &transform) {
    transform_ = transform;
}

float Camera::get_pixel_size() const {
    return pixel_size_;
}
