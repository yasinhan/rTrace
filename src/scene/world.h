//
// Created by han on 3/26/24.
//

#ifndef RAY_TRACE_WORLD_H
#define RAY_TRACE_WORLD_H

#include <vector>
#include "src/shape/shape.h"
#include "src/light/light.h"

class World {
public:
    World();

    ~World() = default;

    [[nodiscard]] Light *get_light() const;

    void set_light(Light *light);

    void add_shape(Shape *shape);

private:

    std::vector<Shape*> objects_;
    Light* light_ = nullptr;
};

#endif //RAY_TRACE_WORLD_H
