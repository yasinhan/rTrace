//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_MATRIX_H
#define RAY_TRACE_MATRIX_H

class Matrix {

public:

    Matrix(int w, int h);

private:
    int w, h;
    float *data;
};


#endif //RAY_TRACE_MATRIX_H
