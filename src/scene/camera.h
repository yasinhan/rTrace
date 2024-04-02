//
// Created by han on 4/2/24.
//

#ifndef RAY_TRACE_CAMERA_H
#define RAY_TRACE_CAMERA_H

#include "src/primitive/matrix.h"

class Camera {
public:
    Camera(int h_size, int v_size, float field_of_view);

    ~Camera() = default;

    int get_h_size() const;

    int get_v_size() const;

    float get_field_of_view() const;

    float get_pixel_size() const;

    const Matrix &get_transform() const;

    void set_transform(const Matrix &transform);

private:
    int h_size_, v_size_;
    float field_of_view_, pixel_size_;
    Matrix transform_ = Matrix::build_identity_matrix(4);
};


#endif //RAY_TRACE_CAMERA_H
