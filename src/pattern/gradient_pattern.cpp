//
// Created by han on 4/15/24.
//

#include "gradient_pattern.h"
#include <cmath>

GradientPattern::GradientPattern(const Color &a, const Color &b) : a_(a), b_(b) {}

Color GradientPattern::color_at_pattern(const Tuple &point) const {
    auto color_distance = b_ - a_;
    auto fraction = point.getX() - std::floor(point.getX());

    return a_ + color_distance * fraction;
}
