//
// Created by han on 4/15/24.
//

#ifndef RAY_TRACE_GRADIENT_PATTERN_H
#define RAY_TRACE_GRADIENT_PATTERN_H
#include "pattern.h"

class GradientPattern : public Pattern {
public:
    GradientPattern(const Color &a, const Color &b);

    ~GradientPattern() = default;

     [[nodiscard]] Color color_at_pattern(const Tuple &point) const override;

private:
    Color a_, b_;

};

#endif //RAY_TRACE_GRADIENT_PATTERN_H
