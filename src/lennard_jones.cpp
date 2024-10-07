#include "lennard_jones.h"
#include <cmath>

LennardJones::LennardJones(double epsilon, double sigma)
    : m_epsilon(epsilon), m_sigma(sigma) {}

std::vector<double> LennardJones::computeForce(const Particle& p1, const Particle& p2) const {
    std::vector<double> r_vec(3);
    double r2 = 0.0;
    for (size_t i = 0; i < 3; ++i) {
        r_vec[i] = p1.getPosition()[i] - p2.getPosition()[i];
        r2 += r_vec[i] * r_vec[i];
    }
    double r = std::sqrt(r2);
    double s_over_r = m_sigma / r;
    double s_over_r6 = std::pow(s_over_r, 6);
    double s_over_r12 = s_over_r6 * s_over_r6;
    double coeff = 24 * m_epsilon * (2 * s_over_r12 - s_over_r6) / r2;

    std::vector<double> force(3);
    for (size_t i = 0; i < 3; ++i) {
        force[i] = coeff * r_vec[i];
    }
    return force;
}

double LennardJones::computePotentialEnergy(const Particle& p1, const Particle& p2) const {
    double r2 = 0.0;
    for (size_t i = 0; i < 3; ++i) {
        double diff = p1.getPosition()[i] - p2.getPosition()[i];
        r2 += diff * diff;
    }
    double r = std::sqrt(r2);
    double s_over_r = m_sigma / r;
    double s_over_r6 = std::pow(s_over_r, 6);
    double s_over_r12 = s_over_r6 * s_over_r6;
    return 4 * m_epsilon * (s_over_r12 - s_over_r6);
}
