#include "headers/time_series_generator.h"
#include "headers/sin_wave_generator.h"
#include "headers/gaussian_generator.h"
#include "headers/step_generator.h"
#include "headers/time_series_dataset.h"
#include "headers/knn.h"

#include <iostream>

using namespace std;

int main() {
    // Test StepGenerator
    cout << "Generating a time series from a step function :"<< endl;
    StepGenerator stepGen;
    vector<double> stepTimeSeries = stepGen.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(stepTimeSeries);

    // Test SinWaveGenerator
    cout << "Generating a time series from a sine wave function:"<< endl;
    SinWaveGenerator sinWaveGen;
    sinWaveGen.setAmplitude(1.0);
    sinWaveGen.setFrequency(0.1);
    sinWaveGen.setInitialPhase(0.0);
    vector<double> sinWaveTimeSeries = sinWaveGen.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(sinWaveTimeSeries);

    // Test GaussianGenerator
    cout << "Generating a time series from a Gaussian distribution:"<< endl;
    GaussianGenerator gaussianGen;
    gaussianGen.setMeanValue(0.0);
    gaussianGen.setStdValue(1.0);
    vector<double> gaussianTimeSeries = gaussianGen.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(gaussianTimeSeries);

    // Test TimeSeriesDataset
    cout <<"Testing TimeSeriesDataset functions:"<< endl;
    TimeSeriesDataset dataset;
    dataset.setZNormalize(true);
    dataset.setData(gaussianTimeSeries);
    vector<double> normalizedData = dataset.getData();
    cout <<"Normalized Gaussian Time Series:"<< endl;
    TimeSeriesGenerator::printTimeSeries(normalizedData);

    // Calculate Euclidean distance between two time series
    double euclideanDist = dataset.euclidean_distance(stepTimeSeries, sinWaveTimeSeries);
    cout <<"Euclidean distance between step and sine wave time series:"<< euclideanDist << endl;

    // Calculate Dynamic Time Warping distance between two time series
    double dtwDist = dataset.dynamic_time_warping(stepTimeSeries, sinWaveTimeSeries);
    cout <<"Dynamic Time Warping distance between step and sine wave time series:"<< dtwDist << endl;

    cout << "end of tests of functions/methods" << endl;

    TimeSeriesDataset trainData(false, true), testData(false, false);
    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;
    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian1, 0);
    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2, 0);
    vector<double> sin1 = swg.generateTimeSeries(11);

    trainData.addTimeSeries(sin1, 1);
    vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2, 1);
    vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1, 2);
    vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2, 2);
    vector <int > ground_truth;
    testData.addTimeSeries(gsg.generateTimeSeries(11));
    ground_truth.push_back(0);
    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);
    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);
    KNN knn_1(1, "dtw");
    cout << knn_1.evaluate(trainData.getData(), testData.getData(), ground_truth) << endl ;
    KNN knn_2(2, "euclidean_distance");
    cout << knn_2.evaluate(trainData.getData(), testData.getData(), ground_truth) << endl ;
    KNN knn_3(3, "euclidean_distance");
    cout << knn_3.evaluate(trainData.getData(), testData.getData(), ground_truth) << endl ;

    return 0;
}