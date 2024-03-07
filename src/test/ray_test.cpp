//
// Created by han on 12/22/23.
//

#include <gtest/gtest.h>
#include "src/primitive/ray.h"
#include <cmath>

class RayTest : public ::testing::Test {
protected:
    RayTest() = default;
    ~RayTest() override = default;
};


TEST(RAY_TEST, TEST_POSITION) {

    auto ray = Ray(Tuple::point(2, 3, 4), Tuple::vector(1, 0, 0));

}
