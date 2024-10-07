#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <chrono>

#include "types.h"

class Benchmark {
public:
    Benchmark();
    void startIteration();
    void endIteration(i64 flops);

    void recordValue(f64 value);
    f64 getAverageValue() const;
    f64 getStandardDeviationValue() const;

    f64 getAverageGflops() const;
    f64 getStandardDeviationGflops() const;
    f64 getAverageIterationTime() const;
    f64 getStandardDeviationIterationTime() const;

private:
    std::vector<f64> m_gflops_per_iteration;
    std::vector<f64> m_iteration_times;
    std::vector<f64> m_values; 
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time;
};

#endif // BENCHMARK_H
