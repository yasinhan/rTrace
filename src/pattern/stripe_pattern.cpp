//
// Created by han on 4/10/24.
//
#include "stripe_pattern.h"

StripePattern::StripePattern(const Color &a, const Color &b) : a_(a), b_(b) {}

Color StripePattern::color_a() const {
    return a_;
}

Color StripePattern::color_b() const {
    return b_;
}
