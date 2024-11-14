//
// Created by MEHDI on 12/11/2024.
//


#include "TimeSeriesDataset.h"
#include <cmath>
#include <numeric>

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

double TimeSeriesDataset::calculateMean(const std::vector<double>& series) {
    return std::accumulate(series.begin(), series.end(), 0.0) / series.size();
}

double TimeSeriesDataset::calculateStdDev(const std::vector<double>& series, double mean) {
    double sum = 0.0;
    for (double value : series) {
        sum += (value - mean) * (value - mean);
    }
    return std::sqrt(sum / series.size());
}

std::vector<double> TimeSeriesDataset::zNormalize(const std::vector<double>& series) {
    double mean = calculateMean(series);
    double stdDev = calculateStdDev(series, mean);
    std::vector<double> normalizedSeries;
    normalizedSeries.reserve(series.size());
    for (double value : series) {
        normalizedSeries.push_back((value - mean) / stdDev);
    }
    return normalizedSeries;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> processedSeries = series;
    if (znormalize) {
        processedSeries = zNormalize(series);
    }
    data.push_back(processedSeries);
    labels.push_back(label);
    maxLength = std::max(maxLength, static_cast<int>(series.size()));
    numberOfSamples++;
}

const std::vector<std::vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const std::vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}
