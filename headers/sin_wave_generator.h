#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H

#include "time_series_generator.h"

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator
{
private:
    double amplitude;
    double frequency;
    double initial_phase;

public:
    SinWaveGenerator();
    ~SinWaveGenerator();

    vector<double> generateTimeSeries(int size) override;

    // Getters
    double getAmplitude() const;
    double getFrequency() const;
    double getInitialPhase() const;

    // Setters
    void setAmplitude(double amplitude);
    void setFrequency(double frequency);
    void setInitialPhase(double initial_phase);

};

#endif