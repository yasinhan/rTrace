//
// Created by han on 4/15/24.
//

#ifndef RAY_TRACE_PATTERN_H
#define RAY_TRACE_PATTERN_H

#include "src/primitive/matrix.h"
#include "src/primitive/color.h"


class Pattern {
public:
    ~Pattern() = default;

    Color color_at(const Tuple &point) const;

    void set_transform(const Matrix &transform);

protected:

    virtual Color color_at_pattern(const Tuple &point) const = 0;

    Matrix trans_ = Matrix::build_identity_matrix(4);

    Matrix inverse_trans = trans_;

    bool has_trans = false;

};


#endif //RAY_TRACE_PATTERN_H
