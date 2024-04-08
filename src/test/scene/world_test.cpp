//
// Created by han on 3/26/24.
//
#include <gtest/gtest.h>
#include <cmath>
#include "src/primitive/transformation.h"
#include "src/scene/world.h"
#include "src/shape/sphere.h"
#include "src/scene/prepare_computations.h"

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

TEST(WORLD_TEST, TEST_DEFAUL_WORLD_iNTERSECT) {
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