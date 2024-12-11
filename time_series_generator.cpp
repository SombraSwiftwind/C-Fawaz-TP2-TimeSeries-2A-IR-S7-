#include "headers/time_series_generator.h"
#include <iostream>
#include <vector>

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator()
: seed(0) {
}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed)
: seed(_seed) {
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> timeSeries) {
    for (const auto& value : timeSeries) {
        cout << value << " ";
    }
    cout << endl;
}

// Getters
int TimeSeriesGenerator::getSeed() {
    return seed;
}

// Setters
void TimeSeriesGenerator::setSeed(int _seed) {
    seed = _seed;
}
