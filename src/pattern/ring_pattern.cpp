//
// Created by han on 4/16/24.
//

#include "ring_pattern.h"
#include <cmath>

RingPattern::RingPattern(const Color &a, const Color &b) : a_(a), b_(b) {}

Color RingPattern::color_at_pattern(const Tuple &point) const {
    auto distance = std::sqrt(std::pow(point.getX(), 2) + std::pow(point.getZ(), 2));
    return (int )std::floor(distance) % 2 == 0 ? a_ : b_;;

}
