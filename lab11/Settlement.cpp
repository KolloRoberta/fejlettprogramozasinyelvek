//
// Created by Kollo Szende-Roberta on 12/3/2024.
//

#include "Settlement.h"

const string &Settlement::getName() const {
    return name;
}

const string &Settlement::getCounty() const {
    return county;
}

int Settlement::getPopulation() const {
    return population;
}

void Settlement::setName(const string &name) {
    Settlement::name = name;
}

void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

ostream &operator<<(ostream &os, Settlement &settlement) {
    os << " Name " << settlement.name << " Country " << settlement.county << " Population " << settlement.population;
    return os;
}
