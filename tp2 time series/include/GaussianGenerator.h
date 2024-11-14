//
// Created by MEHDI on 12/11/2024.
//

#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"


class GaussianGenerator: public TimeSeriesGenerator {
    private:
        double mean;
        double std_deviation;
    public:
        GaussianGenerator(int seed, double mean, double stdDev);
        GaussianGenerator();
        vector<double> generateTimeSeries(int series_length) override;
        void setMean(double mean);
        void setStdDev(double stdDev);
        double getMean() const;
        double getStdDev() const;

};

#endif //GAUSSIANGENERATOR_H
