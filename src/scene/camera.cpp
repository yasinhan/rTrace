//
// Created by han on 4/2/24.
//

#include "camera.h"
#include <cmath>

Camera::Camera(int h_size, int v_size, float field_of_view) : h_size_(h_size), v_size_(v_size), field_of_view_(field_of_view) {
    calculate_pixel_size();
}

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

void Camera::calculate_pixel_size() {
    auto half_view = std::tan(field_of_view_ / 2);
    auto aspect = (float )h_size_ / v_size_;

    if (aspect >= 1) {
        half_width_ = half_view;
        half_height_ = half_view / aspect;
    } else {
        half_width_ = half_view * aspect;
        half_height_ = half_view;
    }
    pixel_size_ = (half_width_ * 2) / h_size_;
}

Ray &Camera::ray_for_pixel(int x, int y) {

    return <#initializer#>;
}
