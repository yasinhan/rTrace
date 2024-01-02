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

TEST(TUPLE_TEST, CREATE_VECTOR_TEST) {
    Tuple vector = Tuple::vector(4, -4, 3);

    EXPECT_EQ(vector.getX(), 4);
    EXPECT_EQ(vector.getY(), -4);
    EXPECT_EQ(vector.getZ(), 3);
    EXPECT_EQ(vector.getW(), 1);
}

TEST(TUPLE_TEST, ADD_TEST) {
    Tuple point = Tuple::point(1, 1, 1);
    Tuple vector = Tuple::vector(1, 1, 1);

    Tuple pointAddVec = point + vector;

    EXPECT_EQ(pointAddVec.getW(), 1);
    EXPECT_EQ(pointAddVec.getX(), 2);
    EXPECT_EQ(pointAddVec.getY(), 2);
    EXPECT_EQ(pointAddVec.getZ(), 2);

}
