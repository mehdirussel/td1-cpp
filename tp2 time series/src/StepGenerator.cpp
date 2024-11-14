//
// Created by MEHDI on 12/11/2024.
//

#include "StepGenerator.h"

#include "StepGenerator.h"
#include <random>

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

std::vector<double> StepGenerator::generateTimeSeries(int series_length) {
    std::vector<double> timeSeries;
    timeSeries.reserve(series_length);
    timeSeries.push_back(0); // first value is always 0

    std::mt19937 rng(seed); // Standard mersenne_twister_engine seeded with the parent class' seed
    std::uniform_int_distribution<> dist(0, 100);
    std::uniform_real_distribution<> prob(0.0, 1.0);

    for (int i = 1; i < series_length; ++i) {
        if (prob(rng) < 0.5) {
            timeSeries.push_back(dist(rng));
        } else {
            timeSeries.push_back(timeSeries.back());
        }
    }

    return timeSeries;
}