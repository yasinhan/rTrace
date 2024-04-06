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

std::unique_ptr<Ray> Camera::ray_for_pixel(int x, int y) {
    auto x_offset = (x + 0.5) * pixel_size_;
    auto y_offset = (y + 0.5) * pixel_size_;

    auto world_x = half_width_ - x_offset;
    auto world_y = half_height_ - y_offset;

    auto transform_inverse = transform_.inverse();
    auto pixel = transform_inverse * Tuple::point((float )world_x, (float )world_y, -1);
    auto origin = transform_inverse * Tuple::point(0, 0, 0);
    auto direction = (pixel - origin).normalized();
    return std::make_unique<Ray>(Ray(origin, direction));
}

std::unique_ptr<Canvas> Camera::render(World &world) {
    auto canvas = Canvas(this->h_size_, this->v_size_);

    for (int y = 0; y < v_size_ - 1; ++y) {
        for (int x = 0; x < h_size_ - 1; ++x) {
            auto ray = ray_for_pixel(x, y);
            auto color = world.color_at(*ray);
            canvas.write_pixel(x, y, color);
        }

    }
    return std::make_unique<Canvas>(canvas);
}
