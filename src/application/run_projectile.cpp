//
// Created by han on 3/25/24.
//
#include "src/display//canvas.h"
#include "src/image/ppm_writer.h"

int run() {
    auto *canvas = new Canvas(10, 2);
    for (int i = 0; i < canvas->get_w(); ++i) {
        for (int j = 0; j < canvas->get_h(); ++j) {
            canvas->write_pixel(i, j, Color(1, 0.8, 0.6));
        }
    }
    auto writer = PPMWriter(canvas);

    writer.write_file(std::string("&HOME/C/rTrace/output/1.ppm"));

}