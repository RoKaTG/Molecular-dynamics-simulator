#ifndef LENNARD_JONES_H
#define LENNARD_JONES_H

#include "potential.h"

class LennardJones : public Potential {
public:
    LennardJones(double epsilon, double sigma);

    std::vector<double> computeForce(const Particle& p1, const Particle& p2) const override;
    double computePotentialEnergy(const Particle& p1, const Particle& p2) const override;

private:
    double m_epsilon;
    double m_sigma;
};

#endif // LENNARD_JONES_H
