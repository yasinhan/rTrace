//
// Created by han on 3/20/24.
//

#ifndef RAY_TRACE_MATERIAL_H
#define RAY_TRACE_MATERIAL_H
#include "src/primitive/color.h"
#include "src/light/light.h"

static const float DEFAULT_AMBIENT = 0.1;
static const float DEFAULT_DIFFUSE = 0.9;
static const float DEFAULT_SPECULAR = 0.9;
static const float DEFAULT_SHININESS = 200.0;


class Material {
public:
    Material();

    ~Material() = default;

    [[nodiscard]] const Color &get_color() const;

    Color lighting(Light &light, Tuple &position, Tuple &eye_vector, Tuple &normal_vector);

    void set_color(const Color &color);

    float get_ambient() const;

    void set_ambient(float ambient);

    float get_diffuse() const;

    void set_diffuse(float diffuse);

    float get_specular() const;

    void set_specular(float specular);

    float get_shininess() const;

    void set_shininess(float shininess);

private:
    Color color_;
    float ambient_, diffuse_, specular_, shininess_;
};

bool operator==(const Material &lhs, const Material &rhs);

#endif //RAY_TRACE_MATERIAL_H
