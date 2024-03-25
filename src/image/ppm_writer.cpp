//
// Created by han on 3/25/24.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include <cmath>
#include "ppm_writer.h"

const int MAX_COLOR_VALUE = 255;
const int MAX_CHARACTER_PER_LINE = 70;

PPMWriter::PPMWriter(Canvas *canvas) : canvas_(canvas) {}

void PPMWriter::write_file(std::string file_name) {
    std::ofstream out;
    out.open(file_name);
    write_stream(out);
    out.close();
}

void PPMWriter::write_stream(std::ostream &stream) {
    write_header(stream);
    for (int i = 0; i < canvas_->get_h(); i++) {
        write_row(stream, i);
    }
}

void PPMWriter::write_header(std::ostream &ostream) {
    ostream << "P3\n";
    ostream << canvas_->get_w() << " " << canvas_->get_h() << "\n";
    ostream << MAX_COLOR_VALUE << "\n";
}

void PPMWriter::write_row(std::ostream &stream, int row_index) {
    int current_line_len = 0;
    for (int i = 0; i < canvas_->get_w(); ++i) {
        auto color = canvas_->pixel_at(i, row_index);
        write_color_element(stream, color.get_red(), current_line_len);
        write_color_element(stream, color.get_green(), current_line_len);
        write_color_element(stream, color.get_blue(), current_line_len);
    }
    stream << "\n";
}

int PPMWriter::color_int(float color) {
    if (color >= 1.0) {
        return MAX_COLOR_VALUE;
    } else if (color <= 0.0) {
        return 0;
    } else {
        return std::ceil(color * MAX_COLOR_VALUE);
    }
}

int determineColorLen(int color) {
    if (color >= 100) {
        return 3;
    } else if (color >= 10) {
        return 2;
    }
    return 1;
}

void PPMWriter::write_color_element(std::ostream &stream, float color, int &current_line_len) {
    int color_value = color_int(color);
    int length = determineColorLen(color_value);

    if (current_line_len == 0) {
        stream << color_value;
        current_line_len += length;
        return;
    }
    if (current_line_len + length + 1 > MAX_CHARACTER_PER_LINE) {
        stream << "\n" << color_value;
        current_line_len = length;
    } else {
        stream << " " << color_value;
        current_line_len += length + 1;
    }
}
