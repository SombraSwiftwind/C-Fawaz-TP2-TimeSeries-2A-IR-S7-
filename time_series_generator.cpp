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
    cout << endl;
    for (int i = 0; i < timeSeries.size(); i++) {
        cout << timeSeries[i] << " ";
    }
    cout << endl;
}
