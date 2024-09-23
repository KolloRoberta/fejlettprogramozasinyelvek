//
// Created by Kollo Szende-Roberta on 9/23/2024.
//

#include <valarray>
#include "functions.h"

int countBits(int number) {
    int szam = 0 ;
    while(number !=0)
    {
        if((number & 1) == 1)
        {
            szam += 1;
        }
        number = number >>1; // igy tolom jobbra
    }
    return szam;
}

bool setBit(int &number, int order) {
    if(order < 0 ||  order > 31)
    {
        return false;
    }
    number = number | (int)pow(2, order);
    return true;
}

double mean(double *array, int numElements) {
    if(numElements ==  0)
    {
        return NAN;
    }
    double sum =0;
    for (int i = 0; i < numElements; ++i) {
        sum+=array[i];
    }
    return sum / numElements;
}

double stddev(double *array, int numElements) {
    if(numElements == 0)
    {
        return NAN;
    }
    double average = mean(array,numElements);

    ////az elterest tarolja el a varians///
    double varians = 0;
    for (int i = 0; i < numElements; ++i) {
        varians += pow(array[i] - average,2);
    }

    return sqrt(varians / numElements);
}
