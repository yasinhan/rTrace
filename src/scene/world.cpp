//
// Created by han on 3/26/24.
//

#include "world.h"
#include "src/shape/sphere.h"
#include "src/primitive/transformation.h"
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
    auto result = Intersections(std::vector<Intersection>());

    for (auto shape : this->objects_) {
        auto intersections = shape->intersect(ray);
        result.merge(intersections);
    }

    return {result};
}

std::vector<Shape *> World::get_objects() const {
    return objects_;
}

Color World::shade_hit(PrepareComputations &prepare) const {
    return prepare.get_object()->get_material().lighting(*light_,
                                                         prepare.get_point(),
                                                         prepare.get_eye_vector(),
                                                         prepare.get_normal_vector());
}

Color World::color_at(Ray &ray) {
    auto intersections = this->intersect(ray);
    auto intersect = intersections.hit();
    if (!intersect.has_value()) {
        return {0, 0, 0};
    }
    auto prepare = PrepareComputations(intersect.value(), intersections, ray);

    return shade_hit(prepare);
}

World default_world() {
    auto world = World();
    auto light = new Light(Color(1, 1, 1), Tuple::point(-10, 10, -10));
    world.set_light(light);

    auto sphere_1 = new Sphere();
    auto material_1 = Material();
    material_1.set_color(Color(0.8, 1.0, 0.6));
    material_1.set_diffuse(0.7);
    material_1.set_specular(0.2);
    sphere_1->set_material(material_1);

    auto sphere_2 = new Sphere();
    sphere_2->set_transform(scaling(0.5, 0.5, 0.5));

    world.add_shape(sphere_1);
    world.add_shape(sphere_2);

    return world;
}

