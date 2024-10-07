#include <iostream>
#include <random>
#include "../include/particle.h"
#include "../include/system.h"
#include "../include/lennard_jones.h"
#include "../include/verlet_integrator.h"
#include "../include/types.h"

i32 main(i32 argc, char* argv[]) {
    // Initialisation du système
    System system;
    const i32 num_particles = 100;
    const f64 box_size = 10.0;

    // Générateur aléatoire
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, box_size);

    // Création des particules avec des positions aléatoires
    for (i32 i = 0; i < num_particles; ++i) {
        std::vector<f64> position = {dis(gen), dis(gen), dis(gen)};
        std::vector<f64> velocity = {0.0, 0.0, 0.0};
        Particle particle(position, velocity, 1.0);
        system.addParticle(particle);
    }

    // Définition du potentiel de Lennard-Jones
    auto potential = std::make_shared<LennardJones>(1.0, 1.0);
    system.setPotential(potential);

    // Création de l'intégrateur
    VerletIntegrator integrator;

    // Boucle de simulation
    const f64 dt = 0.005;
    const i32 num_steps = 1000;

    for (i32 step = 0; step < num_steps; ++step) {
        system.computeForces();
        integrator.integrate(system, dt);

        // Calcul de l'énergie totale
        f64 total_energy = system.computeTotalEnergy();

        // Affichage des informations de simulation
        if (step % 100 == 0) {
            std::cout << "Step: " << step << ", Total Energy: " << total_energy << std::endl;
        }

        // TODO: Ajouter la visualisation en temps réel avec Qt
    }

    return 0;
}
