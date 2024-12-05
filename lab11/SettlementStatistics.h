//
// Created by Kollo Szende-Roberta on 12/3/2024.
//

#ifndef LAB11_SETTLEMENTSTATISTICS_H
#define LAB11_SETTLEMENTSTATISTICS_H

using namespace std;

#include <vector>
#include <iostream>
#include "Settlement.h"

class SettlementStatistics {
public:

    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector<Settlement> findSettlementsByCounty(const string &county) const=0;

    virtual Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const = 0;

    virtual Settlement maxPopulation() const = 0;

    virtual Settlement minPopulation() const = 0;

    virtual vector<Settlement> findSettlementsByName(const string &name) = 0;

};


#endif //LAB11_SETTLEMENTSTATISTICS_H
