//
// Created by han on 12/22/23.
//

#include <gtest/gtest.h>
#include "src/primitive/transformation.h"
#include <cmath>


TEST(TRANSFORMATION_TEST, TRANSLATION_TEST) {
    auto transform = translation(5, -3, 2);
    auto point = Tuple::point(-3, 4, 5);

    auto ret = transform * point;
    ASSERT_FLOAT_EQ(ret.getX(), -8);
    ASSERT_FLOAT_EQ(ret.getY(), 7);
    ASSERT_FLOAT_EQ(ret.getZ(), 3);
}