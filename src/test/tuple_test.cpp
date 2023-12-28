//
// Created by han on 12/22/23.
//

#include <gtest/gtest.h>
#include "src/tuple.h"

class TupleTest : public ::testing::Test {
protected:
    TupleTest() {};
    ~TupleTest() {};
};


TEST(TUPLE_TEST, CREATE_POINT_TEST) {
    Tuple point = Tuple::point(4, -4, 3);

    EXPECT_EQ(point.getX(), 4);
    EXPECT_EQ(point.getY(), -4);
    EXPECT_EQ(point.getZ(), 3);
    EXPECT_EQ(point.getW(), 0);

}