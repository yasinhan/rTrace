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
