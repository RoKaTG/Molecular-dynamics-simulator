#include "verlet_integrator.h"

void VerletIntegrator::integrate(System& system, double dt) {
    auto& particles = system.getParticles();

    // Mise à jour des positions
    #pragma omp parallel for
    for (size_t i = 0; i < particles.size(); ++i) {
        auto position = particles[i].getPosition();
        auto velocity = particles[i].getVelocity();
        auto force = particles[i].getForce();
        double mass = particles[i].getMass();

        std::vector<double> new_position(3);
        for (size_t j = 0; j < 3; ++j) {
            new_position[j] = position[j] + velocity[j] * dt + 0.5 * force[j] / mass * dt * dt;
        }
        particles[i].setPosition(new_position);
    }

    // Calcul des nouvelles forces
    system.computeForces();

    // Mise à jour des vitesses
    #pragma omp parallel for
    for (size_t i = 0; i < particles.size(); ++i) {
        auto velocity = particles[i].getVelocity();
        auto force = particles[i].getForce();
        double mass = particles[i].getMass();

        std::vector<double> new_velocity(3);
        for (size_t j = 0; j < 3; ++j) {
            new_velocity[j] = velocity[j] + 0.5 * force[j] / mass * dt;
        }
        particles[i].setVelocity(new_velocity);
    }
}
