//
// Created by han on 12/22/23.
//

#ifndef RAY_TRACE_VECTOR_H
#define RAY_TRACE_VECTOR_H

class Vector {

public:

    Vector(int length);

    ~Vector();

    void set_value(float value, int index);

    float operator()(int x) const;

    [[nodiscard]] int getLength() const;

private:

    int length;

    float* data;
};



#endif //RAY_TRACE_VECTOR_H
