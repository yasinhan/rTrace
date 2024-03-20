//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_COLOR_H
#define RAY_TRACE_COLOR_H

class Color {

public:

    Color() = default;

    Color(float red, float green, float blue);

    virtual ~Color();

    [[nodiscard]] float get_red() const;

    [[nodiscard]] float get_green() const;

    [[nodiscard]] float get_blue() const;

private:
    float red, green, blue;
};

Color operator+(const Color &lhs, const Color &rhs);

Color operator-(const Color &lhs, const Color &rhs);

Color operator*(const Color &lhs, float scalar);

Color operator*(const Color &lhs, const Color &rhs);

bool operator==(const Color &lhs, const Color &rhs);

#endif //RAY_TRACE_COLOR_H
