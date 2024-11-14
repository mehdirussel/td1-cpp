//
// Created by MEHDI on 12/11/2024.
//

#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    vector<double> zNormalize();


public:
    TimeSeriesDataset(bool znormalize, bool isTrain);
    void addTimeSeries(const vector<double>& series, int label);
    const vector<double>& getData() const;
    const vector<int>& getLabels() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;



};

#endif // TIMESERIESDATASET_H