//
// Created by han on 4/16/24.
//

#ifndef RAY_TRACE_RING_PATTERN_H
#define RAY_TRACE_RING_PATTERN_H
#include "src/primitive/color.h"
#include "pattern.h"

class RingPattern : public Pattern {
public:
    RingPattern(const Color &a, const Color &b);

    ~RingPattern() = default;

    [[nodiscard]] Color color_at_pattern(const Tuple &point) const override;

private:
    Color a_, b_;
};


#endif //RAY_TRACE_RING_PATTERN_H
