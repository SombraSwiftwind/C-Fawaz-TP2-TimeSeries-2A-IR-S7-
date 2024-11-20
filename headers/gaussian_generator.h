#ifndef GAUSSIAN_GENERATOR.H
#define GAUSSIAN_GENERATOR.H

#include "time_series_generator.h"

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator
{
private:
    int mean_value;
    int std_value;

public:
    GaussianGenerator(/* args */);
    ~GaussianGenerator();

    vector<double> generateTimeSeries(int size) override;
};

#endif