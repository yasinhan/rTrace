//
// Created by han on 4/10/24.
//

#ifndef RAY_TRACE_STRIPE_PATTERN_H
#define RAY_TRACE_STRIPE_PATTERN_H

#include "src/primitive/color.h"
#include "src/primitive/tuple.h"
#include "src/primitive/matrix.h"
#include "pattern.h"

class StripePattern : public Pattern {
public:
    StripePattern(Color a, Color b);
    ~StripePattern() = default;

    [[nodiscard]] Color color_a() const;

    [[nodiscard]] Color color_b() const;

    [[nodiscard]] Color color_at_pattern(const Tuple &point) const override;

private:
    Color a_, b_;
};

#endif //RAY_TRACE_STRIPE_PATTERN_H
