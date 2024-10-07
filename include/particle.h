#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>

#include "types.h"

class Particle {
public:
    Particle();
    Particle(const std::vector<f64>& position, const std::vector<f64>& velocity, f64 mass);

    const std::vector<f64>& getPosition() const;
    const std::vector<f64>& getVelocity() const;
    const std::vector<f64>& getForce() const;
    f64 getMass() const;

    void setPosition(const std::vector<f64>& position);
    void setVelocity(const std::vector<f64>& velocity);
    void setForce(const std::vector<f64>& force);
    void resetForce();

    void addForce(const std::vector<f64>& force);

private:
    std::vector<f64> m_position;
    std::vector<f64> m_velocity;
    std::vector<f64> m_force;
    f64 m_mass;
};

#endif // PARTICLE_H
