//
// Created by han on 3/26/24.
//
#include <gtest/gtest.h>
#include <cmath>
#include "src/scene/camera.h"

class CameraTest : public ::testing::Test {
protected:
    CameraTest() = default;
    ~CameraTest() override = default;
};

TEST(CAMERA_TEST, TEST_CAMERA_CREATE) {
    auto camera = Camera(160, 120, M_PI_2);

    ASSERT_EQ(camera.get_h_size(), 160);
    ASSERT_EQ(camera.get_v_size(), 120);
    ASSERT_FLOAT_EQ(camera.get_field_of_view(), M_PI_2);
    ASSERT_EQ(camera.get_transform(), Matrix::build_identity_matrix(4));
}

TEST(CAMERA_TEST, TEST_PIXEL_SIZE_HORIZONTAL_CANVAS) {
    auto camera = Camera(200, 125, M_PI_2);
    ASSERT_FLOAT_EQ(camera.get_pixel_size(), 0.01);
}

TEST(CAMERA_TEST, TEST_PIXEL_SIZE_VERTICAL_CANVAS) {
    auto camera = Camera(125, 200, M_PI_2);
    ASSERT_FLOAT_EQ(camera.get_pixel_size(), 0.01);
}