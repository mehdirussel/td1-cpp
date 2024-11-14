//
// Created by MEHDI on 12/11/2024.
//

#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

double euclidean_distance(const vector<double>& x, const vector<double>& y) {
    if (x.size() != y.size()) {
        throw invalid_argument("Time series must have the same length");
    }

    double sum = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        double diff = x[i] - y[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}
