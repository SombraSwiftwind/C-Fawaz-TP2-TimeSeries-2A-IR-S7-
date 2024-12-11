#include "headers/time_series_dataset.h"

#include <cmath>
#include <iostream>

using namespace std;

TimeSeriesDataset::TimeSeriesDataset()
: znormalize(false), isTrain(false), maxLength(0), numberOfSamples(0)
{
}

TimeSeriesDataset::TimeSeriesDataset(bool _znormalize, bool _isTrain)
: znormalize(_znormalize), isTrain(_isTrain), maxLength(0), numberOfSamples(0)
{
}

TimeSeriesDataset::~TimeSeriesDataset()
{
}

void TimeSeriesDataset::addTimeSeries(vector<double> timeSeries)
{
    for (const auto& value : timeSeries ) {
        data.push_back(value);
    }

}

void TimeSeriesDataset::addTimeSeries(vector<double> timeSeries, int label)
{
    for (const auto& value : timeSeries ) {
        data.push_back(value);
        labels.push_back(label);
    }

}

vector<double> TimeSeriesDataset::ZNormalization(vector<double> timeSeries)
{
    double sum = 0.0;
    double meanValue = 0.0;
    double variance = 0.0;
    double stdValue = 0.0;

    for (double value : timeSeries) {
        sum += value;
    }

    meanValue = sum / timeSeries.size();

    for (double value : timeSeries) {
        variance += (value - meanValue) * (value - meanValue);
    }

    stdValue = sqrt(variance / timeSeries.size());

    for(int i = 0; i < (int) timeSeries.size(); i++) {
        timeSeries[i] = (timeSeries[i]- meanValue) / stdValue;
    }

    return timeSeries;
}


double TimeSeriesDataset::euclidean_distance(const vector<double> time_series1, const vector<double> time_series2)
{
    double sum = 0;

    for (int i = 0; i < (int) time_series1.size(); i++)
    {
        sum += (time_series1[i] - time_series2[i]) * (time_series1[i] - time_series2[i]);
    }

    return sqrt(sum);
}

double TimeSeriesDataset::dynamic_time_warping(const vector<double> time_series1, const vector<double> time_series2)
{
    int n = time_series1.size();
    int m = time_series2.size();
    if (n == m) {
        vector<vector<double>> dtw_matrix(n + 1, vector<double>(m + 1, INFINITY));

        dtw_matrix[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                double cost = (time_series1[i] - time_series2[j]) * (time_series1[i] - time_series2[j]);
                dtw_matrix[i][j] = cost + min(min(dtw_matrix[i-1][j], // insertion
                                                dtw_matrix[i][j-1]), // deletion
                                                dtw_matrix[i-1][j-1]); // match
            }
        }

        return sqrt(dtw_matrix[n][m]);
    } else {
        cout << endl << "Les séries temporelles doivent être de la même taille pour utiliser dynamic time warping!";
        return -1;
    }

}

// Getters
bool TimeSeriesDataset::getZNormalize() const
{
    return znormalize;
}

bool TimeSeriesDataset::getIsTrain() const
{
    return isTrain;
}

vector<double> TimeSeriesDataset::getData() const
{
    return data;
}

vector<int> TimeSeriesDataset::getLabels() const
{
    return labels;
}

int TimeSeriesDataset::getMaxLength() const
{
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const
{
    return numberOfSamples;
}


// Setters
void TimeSeriesDataset::setZNormalize(bool znormalize)
{
    this->znormalize = znormalize;
}

void TimeSeriesDataset::setIsTrain(bool isTrain)
{
    this->isTrain = isTrain;
}

void TimeSeriesDataset::setData(vector<double> data)
{
    if (getZNormalize() == true) {
        data = ZNormalization(data);
        this->data = data;
    }
}

void TimeSeriesDataset::setLabels(vector<int> labels)
{
    this->labels = labels;
}

void TimeSeriesDataset::setMaxLength(int maxLength)
{
    this->maxLength = maxLength;
}

void TimeSeriesDataset::setNumberOfSamples(int numberOfSamples)
{
    this->numberOfSamples = numberOfSamples;
}
