//
// Created by han on 3/26/24.
//
#include <gtest/gtest.h>
#include <cmath>
#include "src/primitive/transformation.h"
#include "src/scene/world.h"
#include "src/shape/sphere.h"
#include "src/shape/plane.h"
#include "src/scene/prepare_computations.h"

class TestPattern : public Pattern {
public:
    Color color_at_pattern(const Tuple &point) const override {
        return Color(point.getX(), point.getY(), point.getZ());
    }

};

class WorldTest : public ::testing::Test {
protected:
    WorldTest() = default;
    ~WorldTest() override = default;
};

TEST(WORLD_TEST, TEST_INIT_WORLD) {
    auto world = World();

    ASSERT_TRUE(nullptr == world.get_light());
    ASSERT_FALSE(world.has_shape());
}

TEST(WORLD_TEST, TEST_DEFAULT_WORLD_INTERSECT) {
    auto world = World();
    auto light = Light(Color(1, 1, 1), Tuple::point(-10, 10, -10));
    world.set_light(&light);

    auto sphere_1 = Sphere();
    auto material_1 = Material();
    material_1.set_color(Color(0.8, 1.0, 0.6));
    material_1.set_diffuse(0.7);
    material_1.set_specular(0.2);
    sphere_1.set_material(material_1);

    auto sphere_2 = Sphere();
    sphere_2.set_transform(scaling(0.5, 0.5, 0.5));

    world.add_shape(&sphere_1);
    world.add_shape(&sphere_2);

    ASSERT_TRUE(world.contains_shape(&sphere_1));
    ASSERT_TRUE(world.contains_shape(&sphere_2));

    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto intersection = world.intersect(ray);

    ASSERT_EQ(intersection.count(), 4);
    ASSERT_FLOAT_EQ(intersection[0].get_t(), 4);
    ASSERT_FLOAT_EQ(intersection[1].get_t(), 4.5);
    ASSERT_FLOAT_EQ(intersection[2].get_t(), 5.5);
    ASSERT_FLOAT_EQ(intersection[3].get_t(), 6);
}

TEST(WORLD_TEST, TEST_WORLD_SHADING_INTERSECTION) {
    auto world = default_world();

    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto shape = world.get_objects()[0];

    auto intersections = shape->intersect(ray);
    auto intersection = intersections.hit();
    ASSERT_TRUE(intersection.has_value());

    auto prepare = PrepareComputations(intersection.value(), intersections, ray);
    auto c = world.shade_hit(prepare);
    ASSERT_EQ(c, Color(0.38066, 0.47583, 0.2855));
}


TEST(WORLD_TEST, TEST_WORLD_SHADING_INTERSECTION_INSIDE) {
    auto world = default_world();
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 0.25, 0));
    world.set_light(&light);
    auto ray = Ray(Tuple::point(0, 0, 0), Tuple::vector(0, 0, 1));
    auto shape = world.get_objects()[1];

    auto intersections = shape->intersect(ray);
    auto intersection = intersections.hit();
    ASSERT_TRUE(intersection.has_value());

    auto prepare = PrepareComputations(intersection.value(), intersections, ray);
    auto c = world.shade_hit(prepare);
    ASSERT_EQ(c, Color(0.90498, 0.90498, 0.90498));
}

TEST(WORLD_TEST, TEST_COLOR_AT_BLACK) {
    auto world = default_world();
    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 1, 0));

    auto color = world.color_at(ray);
    ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(WORLD_TEST, TEST_COLOR_AT_HIT) {
    auto world = default_world();
    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));

    auto color = world.color_at(ray);
    ASSERT_EQ(color, Color(0.38066, 0.47583, 0.2855));
}

TEST(WORLD_TEST, TEST_COLOR_AT_INTERSECTION_BEHIND_RAY) {
    auto world = default_world();
    auto shape_0 = world.get_objects()[0];
    auto material_0 = shape_0->get_material();
    material_0.set_ambient(1);
    shape_0->set_material(material_0);

    auto shape_1 = world.get_objects()[1];
    auto material_1 = shape_1->get_material();
    material_1.set_ambient(1);
    shape_1->set_material(material_1);

    auto ray = Ray(Tuple::point(0, 0, 0.75), Tuple::vector(0, 0, -1));

    auto color = world.color_at(ray);
    ASSERT_EQ(color, shape_1->get_material().get_color());
}

TEST(WORLD_TEST, TEST_NO_SHADOW_WHEN_POINT_LIGHT_COLLINEAR) {
    auto world = default_world();
    auto p = Tuple::point(0, 10, 0);

    ASSERT_FALSE(world.is_shadowed(p));
}

TEST(WORLD_TEST, TEST_SHADOW_WHEN_OBJECT_BETWEEN_POINT_LIGHT) {
    auto world = default_world();
    auto p = Tuple::point(10, -10, 10);

    ASSERT_TRUE(world.is_shadowed(p));
}

TEST(WORLD_TEST, TEST_NO_SHADOW_WHEN_OBJET_BEHIND_LIGHT) {
    auto world = default_world();
    auto p = Tuple::point(-20, 20, -20);

    ASSERT_FALSE(world.is_shadowed(p));
}

TEST(WORLD_TEST, TEST_NO_SHADOW_WHEN_OBJET_BEHIND_POINT) {
    auto world = default_world();
    auto p = Tuple::point(-2, 2, -2);

    ASSERT_FALSE(world.is_shadowed(p));
}

TEST(WORLD_TEST, TEST_SHADE_HIT_INTERSECTION_IN_SHADOW) {
    auto world = World();
    auto light = Light(Color(1, 1, 1), Tuple::point(0, 0, -10));
    world.set_light(&light);

    auto sphere_1 = Sphere();
    auto sphere_2 = Sphere();
    sphere_2.set_transform(translation(0, 0, 10));

    world.add_shape(&sphere_1);
    world.add_shape(&sphere_2);

    auto ray = Ray(Tuple::point(0, 0, 5), Tuple::vector(0, 0, 1));
    auto intersections = sphere_2.intersect(ray);
    auto intersect = intersections.hit();

    ASSERT_TRUE(intersect.has_value());

    auto prepare = PrepareComputations(intersect.value(), intersections, ray);
    auto color = world.shade_hit(prepare);
    ASSERT_EQ(color, Color(0.1, 0.1, 0.1));
}

TEST(WORLD_TEST, TEST_REFLECTED_COLOR_FOR_NONREFLECTIVE_MATERIAL) {
    auto w = default_world();
    auto ray = Ray(Tuple::point(0, 0, 0), Tuple::vector(0, 0, 1));

    auto second_shape = w.get_objects()[1];
    auto material = second_shape->get_material();
    material.set_ambient(1);
    second_shape->set_material(material);

    auto intersections = second_shape->intersect(ray);
    auto intersect = intersections.hit();

    ASSERT_TRUE(intersect.has_value());

    auto prepare = PrepareComputations(intersect.value(), intersections, ray);
    auto color = w.reflected_color(prepare);
    ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(WORLD_TEST, TEST_REFLECTED_COLOR_FOR_REFLECTIVE_MATERIAL) {
    auto w = default_world();
    auto plane = Plane();
    auto material = plane.get_material();
    material.set_reflective(0.5);
    plane.set_material(material);
    plane.set_transform(translation(0, -1, 0));
    w.add_shape(&plane);
    auto ray = Ray(Tuple::point(0, 0, -3), Tuple::vector(0, -sqrt(2) / 2, sqrt(2) / 2));

    auto intersections = w.intersect(ray);
    auto intersect = intersections.hit();

    auto prepare = PrepareComputations(intersect.value(), intersections, ray);
    auto color = w.reflected_color(prepare);
    ASSERT_EQ(color, Color(0.19032, 0.2379, 0.14274));
}

TEST(WORLD_TEST, TEST_SHADE_HIT_REFLECTIVE_MATERIAL) {
    auto w = default_world();
    auto plane = Plane();
    auto material = plane.get_material();
    material.set_reflective(0.5);
    plane.set_material(material);
    plane.set_transform(translation(0, -1, 0));
    w.add_shape(&plane);

    auto ray = Ray(Tuple::point(0, 0, -3), Tuple::vector(0, -sqrt(2) / 2, sqrt(2) / 2));
    auto intersections = w.intersect(ray);
    auto intersect = intersections.hit();

    auto prepare = PrepareComputations(intersect.value(), intersections, ray);
    auto color = w.shade_hit(prepare);
    ASSERT_EQ(color, Color(0.87677, 0.92436, 0.82918));
}

TEST(WORLD_TEST, TEST_COLOR_AT_WITH_MUTUALLY_REFLECTIVE_SURFACES) {
    auto world = World();
    auto light = new Light(Color(1, 1, 1), Tuple::point(0, 0, 0));
    world.set_light(light);

    auto lower = Plane();
    auto material = lower.get_material();
    material.set_reflective(1);
    lower.set_material(material);
    lower.set_transform(translation(0, -1, 0));
    world.add_shape(&lower);

    auto upper = Plane();
    auto material_1 = upper.get_material();
    material_1.set_reflective(1);
    upper.set_material(material_1);
    upper.set_transform(translation(0, 1, 0));
    world.add_shape(&upper);

    auto ray = Ray(Tuple::point(0, 0, 0), Tuple::vector(0, 1, 0));
    auto color = world.color_at(ray, 4);
    ASSERT_EQ(color, Color(9.5, 9.5, 9.5));
}

TEST(WORLD_TEST, TEST_REFLECTED_COLOR_AT_MAXIMUM_RECURSIVE_DEPTH) {
    auto w = default_world();
    auto plane = Plane();
    auto material = plane.get_material();
    material.set_reflective(0.5);
    plane.set_material(material);
    plane.set_transform(translation(0, -1, 0));
    w.add_shape(&plane);
    auto ray = Ray(Tuple::point(0, 0, -3), Tuple::vector(0, -sqrt(2) / 2, sqrt(2) / 2));

    auto intersections = w.intersect(ray);
    auto intersect = intersections.hit();

    auto prepare = PrepareComputations(intersect.value(), intersections, ray);
    auto color = w.reflected_color(prepare, 0);
    ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(WORLD_TEST, TEST_REFRACTED_COLOR_WITH_OPAQUE_SURFACE) {
    auto w = default_world();
    auto shape = w.get_objects()[0];

    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto intersections = Intersections(std::vector<Intersection>{Intersection(4, shape), Intersection(6, shape)});
    auto intersection = intersections[0];
    auto prepare = PrepareComputations(intersection, intersections, ray);

    auto color = w.refracted_color(prepare, 5);
    ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(WORLD_TEST, TEST_REFRACTED_COLOR_MAXIMUM_DEPTH) {
    auto w = default_world();
    auto shape = w.get_objects()[0];
    auto material = shape->get_material();
    material.set_transparency(1.0);
    material.set_refractive_index(1.5);
    shape->set_material(material);

    auto ray = Ray(Tuple::point(0, 0, -5), Tuple::vector(0, 0, 1));
    auto intersections = Intersections(std::vector<Intersection>{Intersection(4, shape), Intersection(6, shape)});
    auto intersection = intersections[0];
    auto prepare = PrepareComputations(intersection, intersections, ray);

    auto color = w.refracted_color(prepare, 0);
    ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(WORLD_TEST, TEST_REFRACTED_COLOR_TOTAL_INTERNAL_REFLECTION) {
    auto w = default_world();
    auto shape = w.get_objects()[0];
    auto material = shape->get_material();
    material.set_transparency(1.0);
    material.set_refractive_index(1.5);
    shape->set_material(material);

    auto ray = Ray(Tuple::point(0, 0, sqrt(2) / 2), Tuple::vector(0, 1, 0));
    auto intersections = Intersections(std::vector<Intersection>{Intersection(-sqrt(2) / 2, shape), Intersection(sqrt(2) / 2, shape)});
    auto intersection = intersections[1];
    auto prepare = PrepareComputations(intersection, intersections, ray);

    auto color = w.refracted_color(prepare, 5);
    ASSERT_EQ(color, Color(0, 0, 0));
}

TEST(WORLD_TEST, TEST_REFRACTED_COLOR_WITH_REFRACTED_RAY) {
    auto w = default_world();
    auto shape_0 = w.get_objects()[0];
    auto material_0 = shape_0->get_material();
    material_0.set_ambient(1.0);
    material_0.set_pattern(new TestPattern());
    shape_0->set_material(material_0);

    auto shape_1 = w.get_objects()[1];
    auto material_1 = shape_1->get_material();
    material_1.set_transparency(1.0);
    material_1.set_refractive_index(1.5);
    shape_1->set_material(material_1);

    auto ray = Ray(Tuple::point(0, 0, 0.1), Tuple::vector(0, 1, 0));
    auto intersections = w.intersect(ray);

    auto intersection = intersections[2];
    auto prepare = PrepareComputations(intersection, intersections, ray);
    auto color = w.refracted_color(prepare, 5);
    ASSERT_EQ(color, Color(0, 0.99888, 0.04725));
}

TEST(WORLD_TEST, TEST_SHADE_HIT_WITH_TRANSPARENT_MATERIAL) {
    auto w = default_world();

    auto floor = Plane();
    floor.set_transform(translation(0, -1, 0));
    auto floor_material = floor.get_material();
    floor_material.set_transparency(0.5);
    floor_material.set_refractive_index(1.5);
    floor.set_material(floor_material);
    w.add_shape(&floor);

    auto ball = Sphere();
    ball.set_transform(translation(0, -3.5, -0.5));
    auto ball_material = ball.get_material();
    ball_material.set_color(Color(1, 0, 0));
    ball_material.set_ambient(0.5);
    ball.set_material(ball_material);
    w.add_shape(&ball);

    auto ray = Ray(Tuple::point(0, 0, -3), Tuple::vector(0, -(float ) sqrt(2) / 2, (float ) sqrt(2) / 2));

    auto intersections = w.intersect(ray);
    auto intersection = intersections[0];
    auto prepare = PrepareComputations(intersection, intersections, ray);
    auto color = w.shade_hit(prepare, 5);
    ASSERT_EQ(color, Color(0.93642, 0.68642, 0.68642));
}