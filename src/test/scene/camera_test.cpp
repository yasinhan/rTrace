//
// Created by han on 3/26/24.
//
#include <gtest/gtest.h>
#include <cmath>
#include "src/scene/camera.h"
#include "src/primitive/transformation.h"

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

TEST(CAMERA_TEST, TEST_RAY_THROUGH_CENTER_OF_CANVAS) {
    auto camera = Camera(201, 101, M_PI_2);
    auto ray = camera.ray_for_pixel(100, 50);
    ASSERT_EQ(ray.get_origin(), Tuple::point(0, 0, 0));
    ASSERT_EQ(ray.get_direction(), Tuple::vector(0, 0, -1));
}

TEST(CAMERA_TEST, TEST_RAY_THROUGH_CORNER_OF_CANVAS) {
    auto camera = Camera(201, 101, M_PI_2);
    auto ray = camera.ray_for_pixel(0, 0);
    ASSERT_EQ(ray.get_origin(), Tuple::point(0, 0, 0));
    ASSERT_EQ(ray.get_direction(), Tuple::vector(0.66519, 0.33259, -0.66851));
}

TEST(CAMERA_TEST, TEST_RAY_WHEN_CAMERA_TRANSFORM) {
    auto camera = Camera(201, 101, M_PI_2);
    auto transform = rotate_y(M_PI_4) * translation(0, -2, 5);
    camera.set_transform(transform);
    auto ray = camera.ray_for_pixel(100, 50);
    ASSERT_EQ(ray.get_origin(), Tuple::point(0, 2, -5));
    ASSERT_EQ(ray.get_direction(), Tuple::vector(sqrt(2) / 2, 0, -sqrt(2) / 2));
}