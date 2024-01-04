//
// Created by han on 12/22/23.
//

#ifndef RAY_TRACE_TUPLE_H
#define RAY_TRACE_TUPLE_H

#include <memory>

class Tuple {

public:
    Tuple(float x, float y, float z, float w);

    ~Tuple();

    bool equals(const Tuple& other);

    [[nodiscard]] float getX() const;

    [[nodiscard]] float getY() const;

    [[nodiscard]] float getZ() const;

    [[nodiscard]] float getW() const;

    static std::unique_ptr<Tuple> point(float x, float y, float z);

    static std::unique_ptr<Tuple> vector(float x, float y, float z);

    [[nodiscard]] float get_magnitude() const;

    [[nodiscard]] std::unique_ptr<Tuple> negate() const;

    std::unique_ptr<Tuple> normalized() const;

private:

    float x, y, z;
    int w;
};

Tuple operator+(const Tuple& lhs, const Tuple& rhs);

Tuple operator-(const Tuple &lhs, const Tuple &rhs);

#endif //RAY_TRACE_TUPLE_H
