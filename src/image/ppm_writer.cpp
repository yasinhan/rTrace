//
// Created by han on 3/25/24.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include <cmath>
#include "ppm_writer.h"

const int MAX_COLOR_VALUE = 255;

PPMWriter::PPMWriter(Canvas *canvas) : canvas_(canvas) {}

void PPMWriter::write_file(std::string file_name) {
    std::ofstream out;
    out.open(file_name);
    write_stream(out);
    out.close();
}

void PPMWriter::write_stream(std::ostream &stream) {

}

void PPMWriter::write_header(std::ostream &ostream) {
    ostream << "P3\n";
    ostream << canvas_->get_w() << " " << canvas_->get_h() << "\n";
    ostream << MAX_COLOR_VALUE << "\n";
}

void PPMWriter::write_row(std::ostream &stream, int row_index) {

}

int PPMWriter::color_int(float color) {
    if (color >= 1.0) {
        return MAX_COLOR_VALUE;
    } else if (color <= 0.0) {
        return 0;
    } else {
        return std::ceil(color * MAX_COLOR_VALUE);
    }
    return 0;
}
