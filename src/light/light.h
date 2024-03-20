//
// Created by han on 3/20/24.
//

#ifndef RAY_TRACE_LIGHT_H
#define RAY_TRACE_LIGHT_H
#include "src/primitive/color.h"
#include "src/primitive/tuple.h"


class Light {
public:
    Light(const Color &intensity, const Tuple &position);

    ~Light() = default;

    const Color &get_intensity() const;

    const Tuple &get_position() const;

private:
    Color intensity_;
    Tuple position_;
};

#endif //RAY_TRACE_LIGHT_H
