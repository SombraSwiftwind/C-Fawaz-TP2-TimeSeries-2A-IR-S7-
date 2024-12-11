#ifndef TIME_SERIES_DATASET_H
#define TIME_SERIES_DATASET_H

#include <vector>

using namespace std;

class TimeSeriesDataset 
{
private:
    bool znormalize;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numerOfSamples;

public:
    TimeSeriesDataset();
    ~TimeSeriesDataset();

    vector<double> ZNormalization(vector<double>);
    double euclidean_distance(const vector<double>, const vector<double>);
    double dynamic_time_warping(const vector<double>, const vector<double>);

    // Getters
    bool getZNormalize() const;
    bool getIsTrain() const;
    vector<double> getData() const;
    vector<int> getLabels() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;

    // Setters
    void setZNormalize(bool znormalize);
    void setIsTrain(bool isTrain);
    void setData(vector<double> data);
    void setLabels(vector<int> labels);
    void setMaxLength(int maxLength);
    void setNumberOfSamples(int numberOfSamples);

};

#endif