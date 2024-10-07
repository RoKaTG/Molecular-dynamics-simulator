#ifndef LENNARD_JONES_H
#define LENNARD_JONES_H

#include "potential.h"
#include "types.h"

class LennardJones : public Potential {
public:
    LennardJones(f64 epsilon, f64 sigma);

    std::vector<f64> computeForce(const Particle& p1, const Particle& p2) const override;
    f64 computePotentialEnergy(const Particle& p1, const Particle& p2) const override;

    i64 getFlopsPerInteraction() const override;

private:
    f64 m_epsilon;
    f64 m_sigma;
};

#endif // LENNARD_JONES_H
