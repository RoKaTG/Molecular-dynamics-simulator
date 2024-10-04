#ifndef POTENTIAL_H
#define POTENTIAL_H

#include "particle.h"
#include <vector>

class Potential {
public:
    virtual ~Potential() = default;

    virtual std::vector<double> computeForce(const Particle& p1, const Particle& p2) const = 0;
    virtual double computePotentialEnergy(const Particle& p1, const Particle& p2) const = 0;
};

#endif // POTENTIAL_H