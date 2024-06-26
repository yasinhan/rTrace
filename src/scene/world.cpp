//
// Created by han on 3/26/24.
//

#include "world.h"
#include "src/shape/sphere.h"
#include "src/primitive/transformation.h"
#include "src/math.h"
#include <algorithm>
#include <cmath>

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

Color World::shade_hit(PrepareComputations &prepare, int depth) const {
    auto is_shadowed = this->is_shadowed(prepare.get_over_point());
    auto surface = prepare.get_object()->get_material().lighting(*light_,
                                                         prepare.get_point(),
                                                         prepare.get_eye_vector(),
                                                         prepare.get_normal_vector(),
                                                         is_shadowed,
                                                         prepare.get_object());
    auto reflected = reflected_color(prepare, depth);
    auto refracted = refracted_color(prepare, depth);
    return surface + reflected + refracted;
}

Color World::color_at(Ray &ray, int depth) const {
    auto intersections = this->intersect(ray);
    auto intersect = intersections.hit();
    if (!intersect.has_value()) {
        return {0, 0, 0};
    }
    auto prepare = PrepareComputations(intersect.value(), intersections, ray);

    return shade_hit(prepare, depth);
}

bool World::is_shadowed(const Tuple &point) const {
    auto vec = light_->get_position() - point;
    auto distance = vec.get_magnitude();
    auto direction = vec.normalized();

    auto ray = Ray(point, direction);
    auto intersections = this->intersect(ray);
    auto intersect = intersections.hit();

    return intersect.has_value() && intersect.value().get_t() < distance;
}

Color World::reflected_color(PrepareComputations &prepare, int depth) const {
    if (depth < 1) {
        return {0, 0, 0};
    }
    auto reflective = prepare.get_object()->get_material().get_reflective();
    if (epsilon(reflective, 0)) {
        return {0, 0, 0};
    }
    auto reflected_ray = Ray(prepare.get_over_point(), prepare.get_reflect_vector());
    auto color = this->color_at(reflected_ray, depth - 1);
    return color * prepare.get_object()->get_material().get_reflective();
}

Color World::refracted_color(PrepareComputations &prepare, int remaining) const {
    if (remaining == 0) {
        return {0, 0, 0};
    }
    if (epsilon(prepare.get_object()->get_material().get_transparency(), 0)) {
        return {0, 0, 0};
    }
    auto ratio = prepare.get_n1() / prepare.get_n2();
    auto cos_i = prepare.get_eye_vector().dot(prepare.get_normal_vector());
    auto sin2_t = ratio * ratio * (1 - cos_i * cos_i);
    if (sin2_t > 1) {
        return {0, 0, 0};
    }
    auto cos_t = (float )sqrt(1 - sin2_t);
    auto direction = prepare.get_normal_vector() * (ratio * cos_i - cos_t) - prepare.get_eye_vector() * ratio;
    auto refracted_ray = Ray(prepare.get_under_point(), direction);
    return color_at(refracted_ray, remaining - 1) * prepare.get_object()->get_material().get_transparency();
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

