//
// Created by han on 3/26/24.
//
#include <gtest/gtest.h>
#include <cmath>
#include "src/primitive/transformation.h"
#include "src/scene/world.h"
#include "src/shape/sphere.h"

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

}