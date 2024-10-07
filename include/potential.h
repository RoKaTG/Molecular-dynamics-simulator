#ifndef POTENTIAL_H
#define POTENTIAL_H

#include <vector>

#include "particle.h"
#include "types.h"

class Potential {
public:
    virtual ~Potential() = default;

    virtual std::vector<f64> computeForce(const Particle& p1, const Particle& p2) const = 0;
    virtual f64 computePotentialEnergy(const Particle& p1, const Particle& p2) const = 0;
};

#endif // POTENTIAL_H