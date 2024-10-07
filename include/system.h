#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <memory>

#include "particle.h"
#include "potential.h"
#include "types.h"

class System {
public:
    System();

    void addParticle(const Particle& particle);
    void setPotential(std::shared_ptr<Potential> potential);

    std::vector<Particle>& getParticles();
    const std::vector<Particle>& getParticles() const;

    void computeForces();

    f64 computeTotalEnergy() const;

    i64 getNumberOfInteractions() const;

private:
    std::vector<Particle> m_particles;
    std::shared_ptr<Potential> m_potential;
};

#endif // SYSTEM_H
