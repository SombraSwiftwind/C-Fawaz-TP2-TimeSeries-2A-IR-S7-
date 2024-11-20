#include "headers/gaussian_generator.h"

#include <cmath>

using namespace std;

//#define RAND_MAX 1;

GaussianGenerator::GaussianGenerator()
: mean_value(0), std_value(0) 
{
}

GaussianGenerator::~GaussianGenerator()
{
}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    //double u1 = rand();
    //double u2 = rand();

    double pi = 2*acos(0.0);
    double z0 = sqrt(-2*log2(u1))*cos(2*pi*u2);
	double z1 = sqrt(-2*log2(u1))*sin(2*pi*u2);

	return vector<double>();
}