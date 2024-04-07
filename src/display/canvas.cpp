//
// Created by han on 1/12/24.
//

#include <cstdlib>
#include "canvas.h"
#include <cstring>

Canvas::Canvas(int width, int height) {
    w_ = width;
    h_ = height;
    canvas_ = (float *) calloc(sizeof(float), w_ * h_ * 3);
}

Canvas::~Canvas() {
    free(canvas_);
}

void Canvas::write_pixel(int x, int y, const Color& color) {
    int index = index_of(x, y);
    canvas_[index++] = color.get_red();
    canvas_[index++] = color.get_green();
    canvas_[index++] = color.get_blue();
}

Color Canvas::pixel_at(int x, int y) {
    int index = index_of(x, y);
    float red = canvas_[index++];
    float green = canvas_[index++];
    float blue = canvas_[index++];
    return {red, green, blue};
}

int Canvas::index_of(int x, int y) const {
    return ((y * w_) + x) * 3;
}

int Canvas::get_w() const {
    return w_;
}

int Canvas::get_h() const {
    return h_;
}

Canvas::Canvas(const Canvas &other) {
    w_ = other.w_;
    h_ = other.h_;
    canvas_ = (float *) calloc(sizeof(float), w_ * h_ * 3);
    memcpy(canvas_, other.canvas_, w_ * h_ * 3 * sizeof(float));
}

Canvas &Canvas::operator=(const Canvas &other) {
    if (this != &other) {
        if (w_ == other.w_ && h_ == other.h_) {
            memcpy(canvas_, other.canvas_, w_ * h_ * 3 * sizeof(float));
        } else {
            w_ = other.w_;
            h_ = other.h_;
            free(canvas_);
            canvas_ = (float *) calloc(sizeof(float), w_ * h_ * 3);
            memcpy(canvas_, other.canvas_, w_ * h_ * 3 * sizeof(float));
        }
    }
    return *this;
}
