//
// Created by han on 3/18/24.
//

#ifndef RAY_TRACE_PROJECTILE_H
#define RAY_TRACE_PROJECTILE_H

#include "src/primitive/tuple.h"


class Environment {
public:
    Environment(const Tuple &gravity, const Tuple &wind);

    ~Environment() = default;

    [[nodiscard]] const Tuple &getGravity() const;

    [[nodiscard]] const Tuple &getWind() const;

private:
    Tuple gravity, wind;
};

class Projectile {

public:
    Projectile(const Tuple &position, const Tuple &velocity);

    ~Projectile() = default;

    [[nodiscard]] const Tuple &getPosition() const;

    [[nodiscard]] const Tuple &getVelocity() const;

    Projectile tick(const Environment &env);
private:
    Tuple position, velocity;
};

#endif //RAY_TRACE_PROJECTILE_H
