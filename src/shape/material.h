//
// Created by han on 3/20/24.
//

#ifndef RAY_TRACE_MATERIAL_H
#define RAY_TRACE_MATERIAL_H
#include "src/primitive/color.h"
#include "src/light/light.h"
#include "src/pattern/stripe_pattern.h"

static const float DEFAULT_AMBIENT = 0.1;
static const float DEFAULT_DIFFUSE = 0.9;
static const float DEFAULT_SPECULAR = 0.9;
static const float DEFAULT_SHININESS = 200.0;
static const float DEFAULT_REFLECTIVE = 0.0;
static const float DEFAULT_TRANSPARENCY = 0.0;
static const float REFRACTIVE_INDEX_VACUUM = 1.0;

class Shape;

class Material {
public:
    Material();

    ~Material() = default;

    [[nodiscard]] const Color &get_color() const;

    Color lighting(Light &light, const Tuple &position,
                   const Tuple &eye_vector, const Tuple &normal_vector,
                   bool in_shadow, const Shape *shape) const;

    void set_color(const Color &color);

    float get_ambient() const;

    void set_ambient(float ambient);

    float get_diffuse() const;

    void set_diffuse(float diffuse);

    float get_specular() const;

    void set_specular(float specular);

    float get_shininess() const;

    float get_reflective() const;

    void set_reflective(float reflective);

    void set_shininess(float shininess);

    void set_pattern(Pattern *pattern);

    float get_transparency() const;

    float get_refractive_index() const;

    void set_transparency(float transparency);

    void set_refractive_index(float refractive_index);

    [[nodiscard]] Pattern *get_pattern() const;

private:
    Color color_;
    float ambient_, diffuse_, specular_, shininess_, reflective_, transparency_, refractive_index_;
    Pattern *pattern_ = nullptr;
};

bool operator==(const Material &lhs, const Material &rhs);

#endif //RAY_TRACE_MATERIAL_H
