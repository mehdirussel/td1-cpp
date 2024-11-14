//
// Created by MEHDI on 12/11/2024.
//

#include "SineWaveGenerator.h"
#include <cmath>

SineWaveGenerator::SineWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

SineWaveGenerator::SineWaveGenerator() : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

std::vector<double> SineWaveGenerator::generateTimeSeries(int series_length) {
    std::vector<double> timeSeries;
    timeSeries.reserve(series_length);

    for (int i = 0; i < series_length; ++i) {
        double value = amplitude * std::sin(frequency * i + phase);
        timeSeries.push_back(value);
    }

    return timeSeries;
}
