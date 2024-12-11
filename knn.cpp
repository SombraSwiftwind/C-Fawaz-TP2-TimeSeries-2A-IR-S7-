#include "headers/knn.h"



#include "headers/sin_wave_generator.h"
#include <cmath>

using namespace std;


KNN::KNN()
: k(0), similarity_measure("")
{
}

KNN::KNN(int _k, string _similarity_measure)
: k(_k), similarity_measure(_similarity_measure)
{
}

KNN::~KNN()
{
}

double KNN::evaluate(vector<double> ytest, vector<double> ypred, vector<int> ground_truth) {
    int count = 0;
    double ytest_size = ytest.size();

    for (int i = 0; i< (int) ytest_size - 1; i++) {
        if (ypred[i] == ytest[i]) {
            count++;
        }
    }

    return static_cast<double>(count) / ytest_size;
}

// Getters
int KNN::getK() const {
    return k;
}

string KNN::getSimilarity_measure() const {
    return similarity_measure;
}

// Setters
void KNN::setK(int k) {
    this->k = k;
}

void KNN::setSimilarity_measure(string similarity_measure) {
    this->similarity_measure = similarity_measure;
}