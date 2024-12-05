//
// Created by Kollo Szende-Roberta on 12/3/2024.
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMPL_H
#define LAB11_SETTLEMENTSTATISTICSIMPL_H


#include <map>
#include "SettlementStatistics.h"

using namespace std;

#include <iostream>

class SettlementStatisticsImpl : public SettlementStatistics {
    multimap<string, Settlement> settlements;
public:
    SettlementStatisticsImpl(const string &fileName);

    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    vector<Settlement> findSettlementsByCounty(const string &county) const override;

    vector<Settlement> findSettlementsByName(const string &name) override;

    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    Settlement maxPopulation() const override;

    Settlement minPopulation() const override;
};


#endif //LAB11_SETTLEMENTSTATISTICSIMPL_H
