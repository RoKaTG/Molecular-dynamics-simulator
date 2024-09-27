#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>

class Particle {
public:
    Particle();
    Particle(const std::vector<double>& position, const std::vector<double>& velocity, double mass);

    const std::vector<double>& getPosition() const;
    const std::vector<double>& getVelocity() const;
    const std::vector<double>& getForce() const;
    double getMass() const;

    void setPosition(const std::vector<double>& position);
    void setVelocity(const std::vector<double>& velocity);
    void setForce(const std::vector<double>& force);
    void resetForce();

    void addForce(const std::vector<double>& force);

private:
    std::vector<double> m_position;
    std::vector<double> m_velocity;
    std::vector<double> m_force;
    double m_mass;
};

#endif // PARTICLE_H
