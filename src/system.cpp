#include <omp.h>

#include "../include/system.h"
#include "../include/types.h"

System::System() : m_potential(nullptr) {}

void System::addParticle(const Particle& particle) {
    m_particles.push_back(particle);
}

void System::setPotential(std::shared_ptr<Potential> potential) {
    m_potential = potential;
}

std::vector<Particle>& System::getParticles() {
    return m_particles;
}

const std::vector<Particle>& System::getParticles() const {
    return m_particles;
}

void System::computeForces() {
    // Réinitialiser les forces
    #pragma omp parallel for
    for (size_t i = 0; i < m_particles.size(); ++i) {
        m_particles[i].resetForce();
    }

    // Calcul des forces entre les particules
    #pragma omp parallel for schedule(dynamic)
    for (size_t i = 0; i < m_particles.size(); ++i) {
        for (size_t j = i + 1; j < m_particles.size(); ++j) {
            auto force = m_potential->computeForce(m_particles[i], m_particles[j]);

            // Section critique pour éviter les conditions de course
            #pragma omp critical
            {
                m_particles[i].addForce(force);
                std::vector<f64> negative_force = {-force[0], -force[1], -force[2]};
                m_particles[j].addForce(negative_force);
            }
        }
    }
}

f64 System::computeTotalEnergy() const {
    f64 total_energy = 0.0;

    // Énergie cinétique
    for (const auto& particle : m_particles) {
        auto velocity = particle.getVelocity();
        f64 kinetic_energy = 0.5 * particle.getMass() * (
            velocity[0]*velocity[0] + velocity[1]*velocity[1] + velocity[2]*velocity[2]
        );
        total_energy += kinetic_energy;
    }

    // Énergie potentielle
    for (size_t i = 0; i < m_particles.size(); ++i) {
        for (size_t j = i + 1; j < m_particles.size(); ++j) {
            total_energy += m_potential->computePotentialEnergy(m_particles[i], m_particles[j]);
        }
    }

    return total_energy;
}

i64 System::getNumberOfInteractions() const {
    return static_cast<i64>((m_particles.size() * (m_particles.size() - 1)) / 2);
}