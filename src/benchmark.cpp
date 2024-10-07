#include <numeric>
#include <cmath>

#include "../include/benchmark.h"

Benchmark::Benchmark() {}

void Benchmark::startIteration() {
    m_start_time = std::chrono::high_resolution_clock::now();
}

void Benchmark::endIteration(i64 flops) {
    auto end_time = std::chrono::high_resolution_clock::now();
    f64 iteration_time = std::chrono::duration<f64>(end_time - m_start_time).count(); // en secondes

    m_iteration_times.push_back(iteration_time);

    f64 gflops = (flops / 1e9) / iteration_time;
    m_gflops_per_iteration.push_back(gflops);
}

void Benchmark::recordValue(f64 value) {
    m_values.push_back(value);
}

f64 Benchmark::getAverageValue() const {
    f64 sum = std::accumulate(m_values.begin(), m_values.end(), 0.0);
    return sum / m_values.size();
}

f64 Benchmark::getStandardDeviationValue() const {
    f64 mean = getAverageValue();
    f64 accum = 0.0;
    for (f64 x : m_values) {
        accum += (x - mean) * (x - mean);
    }
    return std::sqrt(accum / m_values.size());
}

f64 Benchmark::getAverageGflops() const {
    f64 sum = std::accumulate(m_gflops_per_iteration.begin(), m_gflops_per_iteration.end(), 0.0);
    return sum / m_gflops_per_iteration.size();
}

f64 Benchmark::getStandardDeviationGflops() const {
    f64 mean = getAverageGflops();
    f64 accum = 0.0;
    for (f64 x : m_gflops_per_iteration) {
        accum += (x - mean) * (x - mean);
    }
    return std::sqrt(accum / m_gflops_per_iteration.size());
}

f64 Benchmark::getAverageIterationTime() const {
    f64 sum = std::accumulate(m_iteration_times.begin(), m_iteration_times.end(), 0.0);
    return sum / m_iteration_times.size();
}

f64 Benchmark::getStandardDeviationIterationTime() const {
    f64 mean = getAverageIterationTime();
    f64 accum = 0.0;
    for (f64 x : m_iteration_times) {
        accum += (x - mean) * (x - mean);
    }
    return std::sqrt(accum / m_iteration_times.size());
}
