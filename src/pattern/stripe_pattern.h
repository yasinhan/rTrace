//
// Created by han on 4/10/24.
//

#ifndef RAY_TRACE_STRIPE_PATTERN_H
#define RAY_TRACE_STRIPE_PATTERN_H

#include "src/primitive/color.h"
#include "src/primitive/tuple.h"
#include "src/primitive/matrix.h"

class StripePattern {
public:
    StripePattern(Color a, Color b);
    ~StripePattern() = default;

    [[nodiscard]] Color color_a() const;

    [[nodiscard]] Color color_b() const;

    [[nodiscard]] Color stripe_at(const Tuple &point) const;

    void set_transform(const Matrix &transform);

private:
    Color a_, b_;

    Matrix trans_ = Matrix::build_identity_matrix(4);

    Matrix inverse_trans = trans_;

    bool has_trans = false;
};

#endif //RAY_TRACE_STRIPE_PATTERN_H
