//
// Created by han on 3/26/24.
//

#include "world.h"
#include <algorithm>

World::World() {}

Light *World::get_light() const {
    return light_;
}

void World::set_light(Light *light) {
    light_ = light;
}

void World::add_shape(Shape *shape) {
    objects_.push_back(shape);
}

bool World::has_shape() const {
    return !objects_.empty();
}

bool World::contains_shape(Shape *shape) const {
    auto it = std::find(objects_.begin(), objects_.end(), shape);
    return it != objects_.end();
}

Intersections World::intersect(const Ray &ray) const {
    return Intersections(std::vector<Intersection>());
}
