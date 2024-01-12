//
// Created by han on 1/12/24.
//

#ifndef RAY_TRACE_CANVAS_H
#define RAY_TRACE_CANVAS_H

#include "primitive/color.h"

class Canvas {

public:

    Canvas(int width, int height);

    void write_pixel(int x, int y, Color);


private:
    int width;
    int height;

    Color** canvas;

};


#endif //RAY_TRACE_CANVAS_H
