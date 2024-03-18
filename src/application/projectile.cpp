//
// Created by han on 3/18/24.
//

#include "projectile.h"
#include <stdexcept>

Environment::Environment(const Tuple &gravity, const Tuple &wind) : gravity(gravity), wind(wind) {
    if (!gravity.isVector()) {
        throw std::invalid_argument("gravity must be vector");
    }
    if (!wind.isVector()) {
        throw std::invalid_argument("wind must be vector");
    }
}

const Tuple &Environment::getGravity() const {
    return gravity;
}

const Tuple &Environment::getWind() const {
    return wind;
}

Projectile::Projectile(const Tuple &position, const Tuple &velocity) : position(position), velocity(velocity) {
    if (!position.isPoint()) {
        throw std::invalid_argument("position must be point");
    }
    if (!velocity.isVector()) {
        throw std::invalid_argument("velocity must be vector");
    }
}

const Tuple &Projectile::getPosition() const {
    return position;
}

const Tuple &Projectile::getVelocity() const {
    return velocity;
}

Projectile Projectile::tick(const Environment &env) {
    auto pos = this->position + this->velocity;
    auto velo = this->velocity + env.getGravity() + env.getWind();
    return {pos, velo};
}
