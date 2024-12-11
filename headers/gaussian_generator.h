#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H

#include "time_series_generator.h"

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator
{
private:
    double meanValue;
    double stdValue;

public:
    GaussianGenerator();
    ~GaussianGenerator();

    vector<double> generateTimeSeries(int size) override;

    // Getters
    double getMeanValue() const;
    double getStdValue() const;

    // Setters
    void setMeanValue(double meanValue);
    void setStdValue(double stdValue);

};

#endif