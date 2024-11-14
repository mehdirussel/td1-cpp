//
// Created by MEHDI on 12/11/2024.
//

#include "GaussianGenerator.h"
#include <cmath>
#include <limits>
#include <random>
#include <vector>
#include <utility>

using namespace std;

GaussianGenerator::GaussianGenerator(int seed, double mean, double stdDev) : TimeSeriesGenerator(seed), mean(mean), std_deviation(stdDev) {}

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(),mean(0),std_deviation(1) {}

double  generateGaussianNoiseBoxMuller(int seed, double mean, double std_deviation){
    constexpr double two_pi = 2.0 * M_PI;

    //initialize the random uniform number generator (runif) in a range 0 to 1
    std::mt19937 rng(seed); // Standard mersenne_twister_engine seeded with the parent's seed
    std::uniform_real_distribution<> runif(mean, std_deviation);

    //create two random numbers, make sure u1 is greater than zero
    double u1, u2;
    do{ u1 = runif(rng);} while (u1 == 0);
    u2 = runif(rng);

    //compute z0 and z1
    auto mag = std_deviation * sqrt(-2.0 * log(u1));
    auto z0  = mag * cos(two_pi * u2) + mean;

    return z0;
}

vector<double> GaussianGenerator::generateTimeSeries(int series_length) {
    vector<double> timeSeries;
    timeSeries.reserve(series_length);
for (int i = 0; i < series_length; i++) {
        timeSeries.push_back(
            generateGaussianNoiseBoxMuller(this->seed,this->getMean(), this->getStdDev())
            );
    }
    return timeSeries;
}









void GaussianGenerator::setMean(double mean) {
    this->mean = mean;
}

void GaussianGenerator::setStdDev(double stdDev) {
    this->std_deviation = stdDev;
}

double GaussianGenerator::getMean() const {
    return mean;
}

double GaussianGenerator::getStdDev() const {
    return std_deviation;
}