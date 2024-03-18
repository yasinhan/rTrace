//
// Created by han on 1/12/24.
//

#ifndef RAY_TRACE_CANVAS_H
#define RAY_TRACE_CANVAS_H

#include "src/primitive/color.h"

class Canvas {

public:

    Canvas(int width, int height);

    ~Canvas();

    void write_pixel(int x, int y, const Color& color);

    Color pixel_at(int x, int y);

private:
    int w;
    int h;

    static int index_of(int x, int y);
    float* canvas;

};


#endif //RAY_TRACE_CANVAS_H
