//
// Created by han on 1/8/24.
//

#include "color.h"
#include "src/math.h"

Color::Color(float red, float green, float blue) : red(red), green(green), blue(blue) {}

Color::~Color() {

}

float Color::get_red() const {
    return red;
}

float Color::get_green() const {
    return green;
}

float Color::get_blue() const {
    return blue;
}

Color operator+(const Color &lhs, const Color &rhs) {
    return {lhs.get_red() + rhs.get_red(),
            lhs.get_green() + rhs.get_green(),
            lhs.get_blue() + rhs.get_blue()};
}

Color operator-(const Color &lhs, const Color &rhs) {
    return {lhs.get_red() - rhs.get_red(),
            lhs.get_green() - rhs.get_green(),
            lhs.get_blue() - rhs.get_blue()};
}

Color operator*(const Color &lhs, float scalar) {
    return {lhs.get_red() * scalar,
            lhs.get_green() * scalar,
            lhs.get_blue() * scalar};
}

Color operator*(const Color &lhs, const Color &rhs) {
    return {lhs.get_red() * rhs.get_red(),
            lhs.get_green() * rhs.get_green(),
            lhs.get_blue() * rhs.get_blue()};
}

bool operator==(const Color &lhs, const Color &rhs) {
    return epsilon(lhs.get_red(), rhs.get_red()) && epsilon(lhs.get_green(), rhs.get_green())
           && epsilon(lhs.get_blue(), rhs.get_blue());
}
