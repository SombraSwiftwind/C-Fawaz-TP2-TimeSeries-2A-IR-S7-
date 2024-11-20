#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

#include <vector>

using namespace std;

class TimeSeriesGenerator {
    private:
        int seed;

    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int _seed);

        vector<double> generateTimeSeries(int size);
        void printTimeSeries(const vector<double>);
};

#endif