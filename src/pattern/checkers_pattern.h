//
// Created by han on 4/16/24.
//

#ifndef RAY_TRACE_CHECKERS_PATTERN_H
#define RAY_TRACE_CHECKERS_PATTERN_H

#include "pattern.h"

class CheckersPattern : public Pattern {
public:

    CheckersPattern(const Color &a, const Color &b);

    ~CheckersPattern() = default;

    [[nodiscard]] Color color_at_pattern(const Tuple &point) const override;

private:
    Color a_, b_;

};


#endif //RAY_TRACE_CHECKERS_PATTERN_H
