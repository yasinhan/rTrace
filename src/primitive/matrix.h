//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_MATRIX_H
#define RAY_TRACE_MATRIX_H

class Matrix {

public:

    Matrix(int w, int h);

    virtual ~Matrix();

    float operator()(int x, int y) const;

    void set_value(float value, int x, int y);

    int getW() const;

    int getH() const;

private:
    int w, h;
    float *data;

    inline int get_index(int x, int y) const;
};

Matrix operator*(const Matrix &lhs, const Matrix &rhs);

bool operator==(const Matrix lhs, const Matrix rhs);

#endif //RAY_TRACE_MATRIX_H
