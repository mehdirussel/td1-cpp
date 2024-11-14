//
// Created by MEHDI on 12/11/2024.
//
// StepGenerator.h

#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(int seed);
    StepGenerator();
    std::vector<double> generateTimeSeries(int series_length) override;
};

#endif // STEPGENERATOR_H