//
// Created by han on 1/8/24.
//

#ifndef RAY_TRACE_COLOR_H
#define RAY_TRACE_COLOR_H

class Color {

public:
    Color(float red, float green, float blue);

    virtual ~Color();

    [[nodiscard]] float getRed() const;

    [[nodiscard]] float getGreen() const;

    [[nodiscard]] float getBlue() const;

private:
    float red, green, blue;
};
#endif //RAY_TRACE_COLOR_H
