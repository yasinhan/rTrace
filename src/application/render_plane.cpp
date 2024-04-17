//
// Created by han on 3/25/24.
//
#include "src/display/canvas.h"
#include "src/shape/sphere.h"
#include "src/shape/plane.h"
#include "src/primitive/transformation.h"
#include "src/scene/world.h"
#include "src/scene/camera.h"
#include "src/image/ppm_writer.h"
#include <cmath>
#include <iostream>
#include <sstream>

int main() {
    auto plane = Plane();
    auto material = plane.get_material();
    material.set_color(Color(1, 1, 1));
    material.set_specular(0);
    auto white_ = Color(1, 1, 1);
    auto black_ = Color(0, 0, 0);
    auto pattern = StripePattern(white_, black_);
    material.set_pattern(&pattern);
    plane.set_transform(rotate_x(M_PI_2));
    plane.set_material(material);

    auto middle = Sphere();
    middle.set_transform(translation(-0.5, 1, 0.5));
    auto material_middle = middle.get_material();
    material_middle.set_color(Color(0.1, 1, 0.5));
    material_middle.set_diffuse(0.7);
    material_middle.set_specular(0.3);
    middle.set_material(material_middle);

    auto right = Sphere();
    right.set_transform(translation(1.5, 0.5, -0.5) * scaling(0.5, 0.5, 0.5));
    auto material_right = right.get_material();
    material_right.set_color(Color(0.5, 1, 0.1));
    material_right.set_diffuse(0.7);
    material_right.set_specular(0.3);
    right.set_material(material_right);

    auto left = Sphere();
    left.set_transform(translation(-1.5, 0.33, -0.75) * scaling(0.33, 0.33, 0.33));
    auto material_left = left.get_material();
    material_left.set_color(Color(1, 0.8, 0.1));
    material_left.set_diffuse(0.7);
    material_left.set_specular(0.3);
    left.set_material(material_left);

    auto world = World();
    auto light = Light(Color(1, 1, 1), Tuple::point(-10, 10, -10));
    world.set_light(&light);
    world.add_shape(&plane);
    world.add_shape(&middle);
    world.add_shape(&right);
    world.add_shape(&left);

    auto camera = Camera(100, 50, M_PI / 3);
    auto from = Tuple::point(0, 1.5, -5);
    auto to = Tuple::point(0, 1, 0);
    auto up = Tuple::vector(0, 1, 0);
    camera.set_transform(view_transform(from, to, up));

    auto canvas = camera.render(world);
    auto writer = PPMWriter(canvas);
    std::ostringstream stream;
    writer.write_stream(stream);
    std::cout << stream.str();

    return 0;
}