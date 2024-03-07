//
// Created by han on 3/7/24.
//

#ifndef RAY_TRACE_INTERSECTION_H
#define RAY_TRACE_INTERSECTION_H
#include <vector>
#include <optional>
#include "tuple.h"

class Intersection {
public:

    explicit Intersection(float t);

    ~Intersection() = default;

    [[nodiscard]] float getT() const;

private:

    float t;
};


#endif //RAY_TRACE_INTERSECTION_H
