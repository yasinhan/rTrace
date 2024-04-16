//
// Created by han on 4/16/24.
//

#include "checkers_pattern.h"
#include <cmath>

CheckersPattern::CheckersPattern(const Color &a, const Color &b) : a_(a), b_(b) {}

Color CheckersPattern::color_at_pattern(const Tuple &point) const {
    auto factor = std::floor(point.getX()) + std::floor(point.getY()) + std::floor(point.getZ());
    return (int ) factor % 2 == 0 ? a_ : b_;;
}
