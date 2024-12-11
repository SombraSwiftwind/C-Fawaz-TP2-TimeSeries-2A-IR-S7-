#include "headers/time_series_generator.h"
#include "headers/sin_wave_generator.h"
#include "headers/gaussian_generator.h"
#include "headers/step_generator.h"
#include "headers/time_series_dataset.h"

#include <iostream>

using namespace std;

int main() {
    // Test StepGenerator
    cout << "Generating a time series from a step function :" << endl;
    StepGenerator stepGen;
    vector<double> stepTimeSeries = stepGen.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(stepTimeSeries);

    // Test SinWaveGenerator
    cout << "Generating a time series from a sine wave function:" << endl;
    SinWaveGenerator sinWaveGen;
    sinWaveGen.setAmplitude(1.0);
    sinWaveGen.setFrequency(0.1);
    sinWaveGen.setInitialPhase(0.0);
    vector<double> sinWaveTimeSeries = sinWaveGen.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(sinWaveTimeSeries);

    // Test GaussianGenerator
    cout << "Generating a time series from a Gaussian distribution:" << endl;
    GaussianGenerator gaussianGen;
    gaussianGen.setMeanValue(0.0);
    gaussianGen.setStdValue(1.0);
    vector<double> gaussianTimeSeries = gaussianGen.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(gaussianTimeSeries);

    // Test TimeSeriesDataset
    cout << "Testing TimeSeriesDataset functions:" << endl;
    TimeSeriesDataset dataset;
    dataset.setZNormalize(true);
    dataset.setData(gaussianTimeSeries);
    vector<double> normalizedData = dataset.getData();
    cout << "Normalized Gaussian Time Series:" << endl;
    TimeSeriesGenerator::printTimeSeries(normalizedData);

    // Calculate Euclidean distance between two time series
    double euclideanDist = dataset.euclidean_distance(stepTimeSeries, sinWaveTimeSeries);
    cout << "Euclidean distance between step and sine wave time series: " << euclideanDist << endl;

    // Calculate Dynamic Time Warping distance between two time series
    double dtwDist = dataset.dynamic_time_warping(stepTimeSeries, sinWaveTimeSeries);
    cout << "Dynamic Time Warping distance between step and sine wave time series: " << dtwDist << endl;


    return 0;
}