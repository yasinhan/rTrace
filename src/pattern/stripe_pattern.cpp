//
// Created by han on 4/10/24.
//
#include "stripe_pattern.h"
#include <cmath>

StripePattern::StripePattern(Color a, Color b) : a_(a), b_(b) {}

Color StripePattern::color_a() const {
    return a_;
}

Color StripePattern::color_b() const {
    return b_;
}

Color StripePattern::color_at_pattern(const Tuple &point) const {
    return (int )std::floor(point.getX()) % 2 == 0 ? a_ : b_;;
}