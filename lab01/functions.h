//
// Created by Kollo Szende-Roberta on 9/23/2024.
//

#ifndef CPP_2024_FUNCTIONS_H
#define CPP_2024_FUNCTIONS_H
using namespace std;
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <utility>
int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
#endif //CPP_2024_FUNCTIONS_H
