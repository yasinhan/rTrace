//
// Created by han on 4/15/24.
//

#include "gradient_pattern.h"
#include "src/primitive/color.h"

GradientPattern::GradientPattern(const Color &a, const Color &b) : a_(a), b_(b) {}

Color GradientPattern::color_at_pattern(const Tuple &point) const {
    return Color();
}
