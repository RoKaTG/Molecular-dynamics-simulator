#include "../include/particle.h"

Particle::Particle()
    : m_position(3, 0.0), m_velocity(3, 0.0), m_force(3, 0.0), m_mass(1.0) {}

Particle::Particle(const std::vector<double>& position, const std::vector<double>& velocity, double mass)
    : m_position(position), m_velocity(velocity), m_force(3, 0.0), m_mass(mass) {}

const std::vector<double>& Particle::getPosition() const { return m_position; }
const std::vector<double>& Particle::getVelocity() const { return m_velocity; }
const std::vector<double>& Particle::getForce() const { return m_force; }
double Particle::getMass() const { return m_mass; }
