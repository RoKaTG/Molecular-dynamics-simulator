#ifndef VERLET_INTEGRATOR_H
#define VERLET_INTEGRATOR_H

#include "integrator.h"
#include "types.h"

class VerletIntegrator : public Integrator {
public:
    void integrate(System& system, f64 dt) override;
};

#endif // VERLET_INTEGRATOR_H
