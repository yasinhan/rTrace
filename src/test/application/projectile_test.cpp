//
// Created by han on 1/8/24.
//

#include "src/application/projectile.h"
#include <gtest/gtest.h>

class ProjectileTest : public ::testing::Test {
protected:
    ProjectileTest() = default;
    ~ProjectileTest() override = default;
};

TEST(PROJECTILE_TEST, TEST_TICK) {
    auto pos = Projectile(Tuple::point(0, 1, 0), Tuple::vector(1, 1, 0));
    auto env = Environment(Tuple::vector(0, -0.1, 0), Tuple::vector(-0.01, 0, 0));

    auto tick_0 = pos.tick(env);
    ASSERT_EQ(tick_0.getPosition(), Tuple::point(1, 2, 0));
}