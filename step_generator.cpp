#include "headers/step_generator.h"
#include <cmath>

using namespace std;

#define RAND_MAX 100;

StepGenerator::StepGenerator()
{
}

StepGenerator::~StepGenerator()
{
}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> generated_series = vector<double>();
    int value = 0; // Valeur à ajouter dans notre série pour chaque instant
    int probability = 0; // Probabilité utile pour simuler la fonction de saut (0, 100)

    // On ajoute une valeur à la série temporelle pour chaque instant
    for(int i = 0; i < size; i++ ) {
        // On génère une probabilité nécessaire pour simuler la fonction de saut (0, 100)
        probability = rand();
        if (probability >= 50) {
            // On génère un entier aléatoire entre 0 et 100 et on l'ajoute à notre série temporelle
            value = rand();
            generated_series.push_back((double) value);
        } else {
            // On garde la valeur de l'instant précédent et on l'ajoute à notre série temporelle
            generated_series.push_back((double) value);
        }
    }

	return generated_series;
}