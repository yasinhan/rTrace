//
// Created by han on 3/20/24.
//

#include "material.h"
#include <cmath>
#include "shape.h"

Material::Material() {
    color_ = Color(1, 1, 1);
    ambient_ = DEFAULT_AMBIENT;
    diffuse_ = DEFAULT_DIFFUSE;
    specular_ = DEFAULT_SPECULAR;
    shininess_ = DEFAULT_SHININESS;
    reflective_ = DEFAULT_REFLECTIVE;
    transparency_ = DEFAULT_TRANSPARENCY;
    refractive_index_ = DEFAULT_REFRACTIVE_INDEX;
}

Color Material::lighting(Light &light,
                         const Tuple &position,
                         const Tuple &eye_vector,
                         const Tuple &normal_vector,
                         bool in_shadow,
                         const Shape *shape) const {
    Color color;
    if (nullptr != shape) {
        color = shape->pattern_at(position);
    } else if (nullptr != pattern_) {
        color = pattern_->color_at(position);
    } else {
        color = this->color_;
    }
    auto effective_color = color * light.get_intensity();
    auto ambient_color = effective_color * this->ambient_;
    if (in_shadow) {
        return ambient_color;
    }

    auto light_vector = (light.get_position() - position).normalized();
    auto light_dot_normal = light_vector.dot(normal_vector);

    Color diffuse_color;
    Color specular_color;
    if (light_dot_normal < 0) {
        diffuse_color = Color(0, 0, 0);
        specular_color = Color(0, 0, 0);
    } else {
        diffuse_color = effective_color * this->diffuse_ * light_dot_normal;

        auto reflect_vector = (-light_vector).reflect(normal_vector);
        auto reflect_dot_eye = reflect_vector.dot(eye_vector);
        if (reflect_dot_eye <= 0) {
            specular_color = Color(0, 0, 0);
        } else {
            auto factor = (float )pow(reflect_dot_eye, this->shininess_);
            specular_color = light.get_intensity() * this->get_specular() * factor;
        }

    }
    return ambient_color + diffuse_color + specular_color;
}

const Color &Material::get_color() const {
    return color_;
}

void Material::set_color(const Color &color) {
    color_ = color;
}

float Material::get_ambient() const {
    return ambient_;
}

void Material::set_ambient(float ambient) {
    ambient_ = ambient;
}

float Material::get_diffuse() const {
    return diffuse_;
}

void Material::set_diffuse(float diffuse) {
    diffuse_ = diffuse;
}

float Material::get_specular() const {
    return specular_;
}

void Material::set_specular(float specular) {
    specular_ = specular;
}

float Material::get_shininess() const {
    return shininess_;
}

void Material::set_shininess(float shininess) {
    shininess_ = shininess;
}

void Material::set_pattern(Pattern *pattern) {
    pattern_ = pattern;
}

Pattern *Material::get_pattern() const {
    return pattern_;
}

float Material::get_reflective() const {
    return reflective_;
}

void Material::set_reflective(float reflective) {
    reflective_ = reflective;
}

float Material::get_transparency() const {
    return transparency_;
}

float Material::get_refractive_index() const {
    return refractive_index_;
}

bool operator==(const Material &lhs, const Material &rhs) {
    return lhs.get_color() == rhs.get_color()
            && lhs.get_ambient() == rhs.get_ambient()
            && lhs.get_diffuse() == rhs.get_diffuse()
            && lhs.get_specular() == rhs.get_specular()
            && lhs.get_shininess() == rhs.get_shininess();
}
