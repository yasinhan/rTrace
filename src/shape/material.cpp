//
// Created by han on 3/20/24.
//

#include "material.h"

Material::Material() {
    color_ = Color(1, 1, 1);
    ambient_ = DEFAULT_AMBIENT;
    diffuse_ = DEFAULT_DIFFUSE;
    specular_ = DEFAULT_SPECULAR;
    shininess_ = DEFAULT_SHININESS;
}

Color Material::lighting(Light &light, Tuple &position, Tuple &eye_vector, Tuple &normal_vector) {
    
    return Color();
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

bool operator==(const Material &lhs, const Material &rhs) {
    return lhs.get_color() == rhs.get_color()
            && lhs.get_ambient() == rhs.get_ambient()
            && lhs.get_diffuse() == rhs.get_diffuse()
            && lhs.get_specular() == rhs.get_specular()
            && lhs.get_shininess() == rhs.get_shininess();
}
