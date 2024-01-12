//
// Created by han on 1/8/24.
//

#include "color.h"

Color::Color(float red, float green, float blue) : red(red), green(green), blue(blue) {}

Color::~Color() {

}

float Color::getRed() const {
    return red;
}

float Color::getGreen() const {
    return green;
}

float Color::getBlue() const {
    return blue;
}

Color operator+(const Color &lhs, const Color &rhs) {
    return {lhs.getRed() + rhs.getRed(),
            lhs.getGreen() + rhs.getGreen(),
            lhs.getBlue() + rhs.getBlue()};
}

Color operator-(const Color &lhs, const Color &rhs) {
    return {lhs.getRed() - rhs.getRed(),
                 lhs.getGreen() - rhs.getGreen(),
                 lhs.getBlue() - rhs.getBlue()};
}

Color operator*(const Color &lhs, float scalar) {
    return {lhs.getRed() * scalar,
            lhs.getGreen() * scalar,
            lhs.getBlue() * scalar};
}

Color operator*(const Color &lhs, const Color &rhs) {
    return {lhs.getRed() * rhs.getRed(),
            lhs.getGreen() * rhs.getGreen(),
            lhs.getBlue() * rhs.getBlue()};
}
