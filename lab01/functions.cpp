//
// Created by Kollo Szende-Roberta on 9/23/2024.
//

#include <valarray>
#include "functions.h"
#include <sstream>

int countBits(int number) {
    int szam = 0;
    while (number != 0) {
        if ((number & 1) == 1) {
            szam += 1;
        }
        number = number >> 1; // igy tolom jobbra
    }
    return szam;
}

bool setBit(int &number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    number = number | (int) pow(2, order);
    return true;
}

double mean(double *array, int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double sum = 0;
    for (int i = 0; i < numElements; ++i) {
        sum += array[i];
    }
    return sum / numElements;
}

double stddev(double *array, int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double average = mean(array, numElements);

    ////az elterest tarolja el a varians///
    double varians = 0;
    for (int i = 0; i < numElements; ++i) {
        varians += pow(array[i] - average, 2);
    }

    return sqrt(varians / numElements);
}

pair<double, double> max2(double *array, int numElements) {
    if (numElements == 0) {
        return make_pair(NAN, NAN);
    }
    if (numElements == 1) {
        return make_pair(array[0], array[0]);
    }
    double max1 = INT_MIN;
    double max2 = INT_MIN;
    for (int i = 0; i < numElements; ++i) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        } else if (array[i] > max2) {
            max2 = array[i];
        }
    }
    if (max1 < max2) {
        return make_pair(max1, max2);
    } else {
        return make_pair(max2, max1);
    }

}

int countWords(string text) {
    istringstream adatfolyam(text);
    string word;
    int sum = 0;
    while (adatfolyam >> word) {
        istringstream szo_adatfolyam(word);
        int szam;
        if (szo_adatfolyam >> szam) {
            sum += szam;
        }
    }
    return sum;
}

int countWords2(string text) {
    istringstream adatfolyam(text);
    string word;
    int number = 0;
    while (adatfolyam >> word) {
        number++;
    }
    return number;
}

string code(string text) {
    string kodolt_szoveg = "";
    for (char karakter: text) {
        if (karakter >= 'a' && karakter <= 'z') {
            kodolt_szoveg += (karakter == 'z') ? 'a' : karakter + 1;
        } else if (karakter >= 'A' && karakter <= 'Z') {

            kodolt_szoveg += (karakter == 'Z') ? 'A' : karakter + 1;
        } else {
            kodolt_szoveg += karakter;
        }
    }
    return kodolt_szoveg;
}

string decode(string text) {
    string dekodolt_szoveg = "";
    for (char karakter: text) {
        if (karakter >= 'a' && karakter <= 'z') {
            dekodolt_szoveg += (karakter == 'z') ? 'a' : karakter - 1;
        } else if (karakter >= 'A' && karakter <= 'Z') {

            dekodolt_szoveg += (karakter == 'Z') ? 'A' : karakter - 1;
        } else {
            dekodolt_szoveg += karakter;
        }
    }
    return dekodolt_szoveg;
}

string capitalizeWords(string text) {
    bool nagyBetuKovetkezik = true;
    for (int i = 0; i < text.length(); ++i) {
        if (isspace(text[i])) {
            nagyBetuKovetkezik = true;
        } else if (nagyBetuKovetkezik) {
            text[i] = toupper(text[i]);
            nagyBetuKovetkezik = false;
        } else {
            text[i] = tolower(text[i]);
        }
    }
    return text;
}
