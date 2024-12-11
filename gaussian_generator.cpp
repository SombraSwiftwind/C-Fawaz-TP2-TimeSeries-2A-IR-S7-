#include "headers/gaussian_generator.h"

#include <cmath>

using namespace std;

//#define RAND_MAX 1;

GaussianGenerator::GaussianGenerator()
: meanValue(0.0), stdValue(1.0) 
{
}

GaussianGenerator::~GaussianGenerator()
{
}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> generated_series = vector<double>();
    //generated_series.reserve(size);
    
    for (int i = 0; i < size; i += 2) {
        double u1 = rand() / static_cast<double>(RAND_MAX);
        double u2 = rand() / static_cast<double>(RAND_MAX);

        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double z1 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);

        generated_series.push_back(meanValue + z0 * stdValue);
        if (i + 1 < size) {
            generated_series.push_back(meanValue + z1 * stdValue);
        }
    }

	return generated_series;
}

// Getters
double GaussianGenerator::getMeanValue() const
{
    return meanValue;
}

double GaussianGenerator::getStdValue() const
{
    return stdValue;
}

// Setters
void GaussianGenerator::setMeanValue(double meanValue)
{
    this->meanValue = meanValue;
}

void GaussianGenerator::setStdValue(double stdValue)
{
    this->stdValue = stdValue;
}