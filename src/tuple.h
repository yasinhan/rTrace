//
// Created by han on 12/22/23.
//

#ifndef RAY_TRACE_TUPLE_H
#define RAY_TRACE_TUPLE_H

class Tuple {

public:
    Tuple(float x, float y, float z, int w);

    ~Tuple();

    bool equals(Tuple other);

    [[nodiscard]] float getX() const;

    float getY() const;

    float getZ() const;

    int getW() const;

    static Tuple point(float x, float y, float z);

    static Tuple vector(float x, float y, float z);

private:

    float x, y, z;
    int w;
};

#endif //RAY_TRACE_TUPLE_H
