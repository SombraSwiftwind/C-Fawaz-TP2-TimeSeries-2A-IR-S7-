#ifndef KNN_H
#define KNN_H

#include <string>
#include <vector>

using namespace std;

class KNN
{
private:
    int k;
    string similarity_measure;

public:
    KNN();
    KNN(int, string);
    ~KNN();
    
    double evaluate(vector<double> trainData, vector<double> testData, vector<int> ground_truth);

    //Getters
    int getK() const;
    string getSimilarity_measure() const;

    //Setters
    void setK(int k);
    void setSimilarity_measure(string);
};


#endif