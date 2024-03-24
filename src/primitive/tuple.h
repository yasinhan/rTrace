//
// Created by han on 12/22/23.
//

#ifndef RAY_TRACE_TUPLE_H
#define RAY_TRACE_TUPLE_H

class Tuple {

public:
    Tuple() {};

    Tuple(float x, float y, float z, float w);

    ~Tuple();

    bool equals(const Tuple& other);

    bool is_point() const;

    bool is_vector() const;

    [[nodiscard]] float getX() const;

    [[nodiscard]] float getY() const;

    [[nodiscard]] float getZ() const;

    [[nodiscard]] float getW() const;

    static Tuple point(float x, float y, float z);

    static Tuple vector(float x, float y, float z);

    [[nodiscard]] float get_magnitude() const;

    [[nodiscard]] Tuple negate() const;

    Tuple normalized() const;

    float dot(const Tuple& other) const;

    float self_dot() const;

    Tuple cross(Tuple& other) const;

    void setW(float w);

    Tuple reflect(const Tuple &in) const;

private:

    float x_, y_, z_;
    float w_;
};

bool operator==(const Tuple &lhs, const Tuple &rhs);

Tuple operator+(const Tuple &lhs, const Tuple &rhs);

Tuple operator-(const Tuple &lhs, const Tuple &rhs);

Tuple operator*(const Tuple &lhs, float rhs);

Tuple operator/(const Tuple &lhs, float rhs);

Tuple operator-(const Tuple &origin);

#endif //RAY_TRACE_TUPLE_H
