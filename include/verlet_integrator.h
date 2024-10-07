#ifndef VERLET_INTEGRATOR_H
#define VERLET_INTEGRATOR_H

#include "integrator.h"

class VerletIntegrator : public Integrator {
public:
    void integrate(System& system, double dt) override;
};

#endif // VERLET_INTEGRATOR_H
