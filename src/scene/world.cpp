//
// Created by han on 3/26/24.
//

#include "world.h"

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
