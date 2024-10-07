// main.cpp
#include <iostream>
#include <random>
#include "particle.h"
#include "system.h"
#include "lennard_jones.h"
#include "verlet_integrator.h"
#include "benchmark.h"
#include "types.h"

int main(int argc, char* argv[]) {
    // Initialisation du système
    System system;
    const i32 num_particles = 1000;
    const f64 box_size = 50.0;

    // Générateur aléatoire
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<f64> dis(0.0, box_size);

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

    // Création du benchmarker
    Benchmark benchmark;

    // Boucle de simulation
    const f64 dt = 0.0005;
    const i32 num_steps = 1000;

    for (i32 step = 0; step < num_steps; ++step) {
        benchmark.startIteration();

        system.computeForces();
        integrator.integrate(system, dt);

        // Calcul du nombre de FLOPs
        i64 flops = system.getNumberOfInteractions() * potential->getFlopsPerInteraction();
        benchmark.endIteration(flops);

        // Calcul de l'énergie totale
        f64 total_energy = system.computeTotalEnergy();

        // Enregistrer l'énergie totale pour le benchmarking
        benchmark.recordValue(total_energy);

        // Affichage des informations de simulation
        if (step % 100 == 0) {
            std::cout << "Steps : " << step << ", Total energy : " << total_energy << std::endl;
        }

        // TODO: Ajouter la visualisation en temps réel avec Qt
    }

    std::cout << "=== Benchmarking Results ===" << std::endl;
    std::cout << "Average GFLOP/s per iteration: " << benchmark.getAverageGflops() << " GFLOP/s" << std::endl;
    std::cout << "Standard deviation of GFLOP/s: " << benchmark.getStandardDeviationGflops() << " GFLOP/s" << std::endl;
    std::cout << "Average iteration time: " << benchmark.getAverageIterationTime() << " seconds" << std::endl;
    std::cout << "Standard deviation of iteration time: " << benchmark.getStandardDeviationIterationTime() << " seconds" << std::endl;
    std::cout << "Average total energy value: " << benchmark.getAverageValue() << std::endl;
    std::cout << "Standard deviation of total energy: " << benchmark.getStandardDeviationValue() << std::endl;

    return 0;
}
