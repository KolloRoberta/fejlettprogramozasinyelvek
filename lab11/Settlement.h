//
// Created by Kollo Szende-Roberta on 12/3/2024.
//

#ifndef LAB11_SETTLEMENT_H
#define LAB11_SETTLEMENT_H

using namespace std;

#include <iostream>

class Settlement {
private:
    string name = " ";
    string county = " ";
    int population = 0;
public:
    Settlement(const string& n = "", const string& c = "", int p = 0)
            : name(n), county(c), population(p) {}
    const string &getName() const;

    const string &getCounty() const;

    int getPopulation() const;

    void setName(const string &name);

    void setCounty(const string &country);

    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, Settlement &settlement);

};


#endif //LAB11_SETTLEMENT_H
