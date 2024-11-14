//
// Created by MEHDI on 12/11/2024.
//

#ifndef SINEWAVEGENERATOR_H
#define SINEWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class SineWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;
public:
    SineWaveGenerator(int seed, double amplitude, double frequency, double phase);
    SineWaveGenerator();
    std::vector<double> generateTimeSeries(int series_length) override;
};

#endif // SINEWAVEGENERATOR_H
