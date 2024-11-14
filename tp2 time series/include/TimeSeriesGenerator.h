//
// Created by MEHDI on 12/11/2024.
//

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
using namespace std;

class TimeSeriesGenerator {
    protected:
      int seed;
    public:
        // Constructor
        TimeSeriesGenerator(int seed): seed(seed) {};
        // default constructor
        TimeSeriesGenerator(): seed(0) {};
        virtual vector<double> generateTimeSeries(int series_length) = 0;
        static void printTimeSeries(const vector<double> timeSeries);
};



#endif //TIMESERIESGENERATOR_H
