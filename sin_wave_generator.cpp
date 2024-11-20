#include "headers/sin_wave_generator.h"
#include <cmath>

using namespace std;


SinWaveGenerator::SinWaveGenerator()
: amplitude(0), frequency(0), initial_phase(0)
{
}

SinWaveGenerator::~SinWaveGenerator()
{
}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> generated_series = vector<double>();
    int value = 0; // Valeur à ajouter dans notre série pour chaque instant

    // On ajoute une valeur à la série temporelle pour chaque instant
    for(int i = 0; i < size; i++ ) {

    }

	return generated_series;
}