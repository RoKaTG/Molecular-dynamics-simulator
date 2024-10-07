#include "../include/particle.h"
#include "../include/types.h"

Particle::Particle()
    : m_position(3, 0.0), m_velocity(3, 0.0), m_force(3, 0.0), m_mass(1.0) {}

Particle::Particle(const std::vector<f64>& position, const std::vector<f64>& velocity, f64 mass)
    : m_position(position), m_velocity(velocity), m_force(3, 0.0), m_mass(mass) {}

const std::vector<f64>& Particle::getPosition() const { return m_position; }
const std::vector<f64>& Particle::getVelocity() const { return m_velocity; }
const std::vector<f64>& Particle::getForce() const { return m_force; }
f64 Particle::getMass() const { return m_mass; }

void Particle::setPosition(const std::vector<f64>& position) { m_position = position; }
void Particle::setVelocity(const std::vector<f64>& velocity) { m_velocity = velocity; }
void Particle::setForce(const std::vector<f64>& force) { m_force = force; }
void Particle::resetForce() { m_force = {0.0, 0.0, 0.0}; }

void Particle::addForce(const std::vector<f64>& force) {
    for (size_t i = 0; i < m_force.size(); ++i) {
        m_force[i] += force[i];
    }
}
