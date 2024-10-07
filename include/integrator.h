#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "system.h"

class Integrator {
public:
    virtual ~Integrator() = default;

    virtual void integrate(System& system, double dt) = 0;
};

#endif // INTEGRATOR_H
