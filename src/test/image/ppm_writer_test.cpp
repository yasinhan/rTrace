//
// Created by han on 3/25/24.
//
#include <gtest/gtest.h>
#include "src/image/ppm_writer.h"


class PPMWriterTest : public ::testing::Test {
protected:
    PPMWriterTest() = default;
    ~PPMWriterTest() override = default;
};

TEST(PPM_WRITER_TEST, TEST_WRITE_STREAM_0) {
    Canvas *canvas = new Canvas(5, 3);
    auto writer = PPMWriter(canvas);

    std::ostringstream stream;
    writer.write_stream(stream);
    ASSERT_EQ(std::string("P3\n5 3\n255\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                          "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                          "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"), stream.str());
    delete canvas;
}

TEST(PPM_WRITER_TEST, TEST_WRITE_STREAM_1) {
    auto *canvas = new Canvas(5, 3);
    canvas->write_pixel(0, 0, Color(1.5, 0, 0));
    canvas->write_pixel(2, 1, Color(0, 0.5, 0));
    canvas->write_pixel(4, 2, Color(-0.5, 0, 1));
    auto writer = PPMWriter(canvas);

    std::ostringstream stream;
    writer.write_stream(stream);
    ASSERT_EQ(std::string("P3\n5 3\n255\n"
                          "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                          "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
                          "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n"), stream.str());
    delete canvas;
}

TEST(PPM_WRITER_TEST, TEST_WRITE_STREAM_2) {
    auto *canvas = new Canvas(10, 2);
    for (int i = 0; i < canvas->get_w(); ++i) {
        for (int j = 0; j < canvas->get_h(); ++j) {
            canvas->write_pixel(i, j, Color(1, 0.8, 0.6));
        }
    }
    auto writer = PPMWriter(canvas);

    std::ostringstream stream;
    writer.write_stream(stream);
    ASSERT_EQ(std::string("P3\n10 2\n255\n"
                          "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
                          "153 255 204 153 255 204 153 255 204 153 255 204 153\n"
                          "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
                          "153 255 204 153 255 204 153 255 204 153 255 204 153\n"), stream.str());
    delete canvas;
}