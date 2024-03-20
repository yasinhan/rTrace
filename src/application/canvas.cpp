//
// Created by han on 1/12/24.
//

#include <cstdlib>
#include "canvas.h"

Canvas::Canvas(int width, int height) {
    w = width;
    h = height;
    canvas = (float *) calloc(sizeof(float), w * h * 3);
}

Canvas::~Canvas() {
    free(canvas);
}

void Canvas::write_pixel(int x, int y, const Color& color) {
    int index = index_of(x, y);
    canvas[index++] = color.get_red();
    canvas[index++] = color.get_green();
    canvas[index++] = color.get_blue();
}

Color Canvas::pixel_at(int x, int y) {
    int index = index_of(x, y);
    float red = canvas[index++];
    float green = canvas[index++];
    float blue = canvas[index++];
    return {red, green, blue};
}

int Canvas::index_of(int x, int y) {
    return x * y + y * 3;
}

