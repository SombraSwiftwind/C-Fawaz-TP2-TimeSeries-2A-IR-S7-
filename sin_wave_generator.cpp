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

    // On ajoute une valeur sinusoïdale à la série temporelle pour chaque instant i
    for(int i = 0; i < size; i++ ) {
        // On utilise la fonction amplitude * sin(frequency * i + initial_phase) pour générer notre série temporelle
        value = amplitude * sin(frequency * i + initial_phase);
        generated_series.push_back(static_cast<double>(value));
    }

	return generated_series;
}

// Getters
double SinWaveGenerator::getAmplitude() const {
    return amplitude;
}

double SinWaveGenerator::getFrequency() const {
    return frequency;
}

double SinWaveGenerator::getInitialPhase() const {
    return initial_phase;
}

// Setters
void SinWaveGenerator::setAmplitude(double amplitude) {
    this->amplitude = amplitude;
}

void SinWaveGenerator::setFrequency(double frequency) {
    this->frequency = frequency;
}

void SinWaveGenerator::setInitialPhase(double initial_phase) {
    this->initial_phase = initial_phase;
}