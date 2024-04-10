//
// Created by han on 4/10/24.
//

#ifndef RAY_TRACE_STRIPE_PATTERN_H
#define RAY_TRACE_STRIPE_PATTERN_H

#include "src/primitive/color.h"

class StripePattern {
public:
    StripePattern(const Color &a, const Color &b);
    ~StripePattern() = default;

    [[nodiscard]] Color color_a() const;

    [[nodiscard]] Color color_b() const;
private:
    Color a_, b_;
};

#endif //RAY_TRACE_STRIPE_PATTERN_H
