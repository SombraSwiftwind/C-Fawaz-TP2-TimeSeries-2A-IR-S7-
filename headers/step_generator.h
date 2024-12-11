#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "time_series_generator.h"

using namespace std;

class StepGenerator : public TimeSeriesGenerator
{
public:
    StepGenerator();
    ~StepGenerator();

    vector<double> generateTimeSeries(int size) override;
};


#endif