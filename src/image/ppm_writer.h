//
// Created by han on 3/25/24.
//

#ifndef RAY_TRACE_PPM_WRITER_H
#define RAY_TRACE_PPM_WRITER_H

#include <string>
#include <ostream>
#include "src/display/canvas.h"

class PPMWriter {
public:
    PPMWriter(Canvas *canvas);

    ~PPMWriter() = default;

    void write_file(std::string file_name);

    void write_stream(std::ostream &stream);

private:
    Canvas *canvas_;

    void write_header(std::ostream &ostream);

    void write_row(std::ostream &stream, int row_index);

    void write_color_element(std::ostream &stream, float color, int &current_line_len);

    int color_int(float color);
};


#endif //RAY_TRACE_PPM_WRITER_H
