#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "system.h"
#include "types.h"

class Integrator {
public:
    virtual ~Integrator() = default;

    virtual void integrate(System& system, f64 dt) = 0;
};

#endif // INTEGRATOR_H
