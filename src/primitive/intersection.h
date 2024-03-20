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

    Intersection(float t, const void *obj);

    ~Intersection() = default;

    [[nodiscard]] float get_t() const;

    [[nodiscard]] const void *get_obj() const;

    bool operator==(Intersection other) const;

private:

    float t;

    const void *obj;
};


#endif //RAY_TRACE_INTERSECTION_H
