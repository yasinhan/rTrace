//
// Created by han on 4/10/24.
//

#ifndef RAY_TRACE_STRIPE_PATTERN_H
#define RAY_TRACE_STRIPE_PATTERN_H

#include "src/primitive/color.h"
#include "src/primitive/tuple.h"

class StripePattern {
public:
    StripePattern(Color a, Color b);
    ~StripePattern() = default;

    [[nodiscard]] Color color_a() const;

    [[nodiscard]] Color color_b() const;

    [[nodiscard]] Color stripe_at(const Tuple &point) const;
private:
    Color a_, b_;
};

#endif //RAY_TRACE_STRIPE_PATTERN_H
