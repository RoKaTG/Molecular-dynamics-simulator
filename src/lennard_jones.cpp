#include <cmath>

#include "../include/lennard_jones.h"
#include "../include/types.h"

LennardJones::LennardJones(f64 epsilon, f64 sigma)
    : m_epsilon(epsilon), m_sigma(sigma) {}

std::vector<f64> LennardJones::computeForce(const Particle& p1, const Particle& p2) const {
    std::vector<f64> r_vec(3);
    f64 r2 = 0.0;
    for (size_t i = 0; i < 3; ++i) {
        r_vec[i] = p1.getPosition()[i] - p2.getPosition()[i];
        r2 += r_vec[i] * r_vec[i];
    }
    f64 r = std::sqrt(r2);
    f64 s_over_r = m_sigma / r;
    f64 s_over_r6 = std::pow(s_over_r, 6);
    f64 s_over_r12 = s_over_r6 * s_over_r6;
    f64 coeff = 24 * m_epsilon * (2 * s_over_r12 - s_over_r6) / r2;

    std::vector<f64> force(3);
    for (size_t i = 0; i < 3; ++i) {
        force[i] = coeff * r_vec[i];
    }
    return force;
}

f64 LennardJones::computePotentialEnergy(const Particle& p1, const Particle& p2) const {
    f64 r2 = 0.0;
    for (size_t i = 0; i < 3; ++i) {
        f64 diff = p1.getPosition()[i] - p2.getPosition()[i];
        r2 += diff * diff;
    }
    f64 r = std::sqrt(r2);
    f64 s_over_r = m_sigma / r;
    f64 s_over_r6 = std::pow(s_over_r, 6);
    f64 s_over_r12 = s_over_r6 * s_over_r6;
    return 4 * m_epsilon * (s_over_r12 - s_over_r6);
}

i64 LennardJones::getFlopsPerInteraction() const {
    return 30; 
}
