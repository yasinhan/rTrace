//
// Created by han on 3/7/24.
//

#ifndef RAY_TRACE_INTERSECTIONS_H
#define RAY_TRACE_INTERSECTIONS_H
#include <vector>
#include <optional>
#include "tuple.h"
#include "intersection.h"

class Intersections {
public:

    explicit Intersections(const std::vector<Intersection> &intersections);

    ~Intersections() = default;

    std::optional<Intersection> hit() const;

    size_t count();

    Intersection operator[](int index);
private:

    std::vector<Intersection> intersections;
};


#endif //RAY_TRACE_INTERSECTIONS_H
