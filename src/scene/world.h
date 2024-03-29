//
// Created by han on 3/26/24.
//

#ifndef RAY_TRACE_WORLD_H
#define RAY_TRACE_WORLD_H

#include <vector>
#include "prepare_computations.h"
#include "src/shape/shape.h"
#include "src/light/light.h"

class World {
public:
    World();

    ~World() = default;

    Intersections intersect(const Ray &ray) const;

    [[nodiscard]] Light *get_light() const;

    void set_light(Light *light);

    void add_shape(Shape *shape);

    bool has_shape() const;

    bool contains_shape(Shape *shape) const;

    [[nodiscard]] const std::vector<Shape *> &get_objects() const;

    [[nodiscard]] Color shade_hit(PrepareComputations prepare) const;

private:

    std::vector<Shape*> objects_;
    Light* light_ = nullptr;
};

World default_world();

#endif //RAY_TRACE_WORLD_H
