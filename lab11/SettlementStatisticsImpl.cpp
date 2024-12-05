//
// Created by Kollo Szende-Roberta on 12/3/2024.
//

#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include "SettlementStatisticsImpl.h"


SettlementStatisticsImpl::SettlementStatisticsImpl(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        throw runtime_error("Nem sikerult megnyitni a fajlt" + fileName);
    }
    string line;
    while (getline(file, line)) {
        stringstream is(line);
        string name, county;
        string populaton;
        getline(is, name, ',');
        getline(is, county, ',');
        getline(is, populaton);
        int pop_int;
        try {
            pop_int = stoi(populaton);

        }
        catch (invalid_argument e) {
            pop_int = 0;
        }
        Settlement temp(name, county, pop_int);
        settlements.emplace(county, temp);
    }
}

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string> counties;
    transform(settlements.begin(), settlements.end(), inserter(counties, counties.begin()), [](const auto &pair) {
        return pair.first;
    });
    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return count_if(settlements.begin(), settlements.end(), [&county](const auto &pair) {
        return pair.first == county;
    });
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;
    auto range = settlements.equal_range(county);
    transform(range.first, range.second, back_inserter(result), [](const auto &pair) {
        return pair.second;
    });
    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    auto it = find_if(settlements.begin(), settlements.end(), [&](const auto &pair) {
        return pair.first == county && pair.second.getName() == name;
    });
    return (it != settlements.end()) ? it->second : Settlement();
}

Settlement SettlementStatisticsImpl::maxPopulation() const {
    auto it = max_element(settlements.begin(), settlements.end(), [](const auto &a, const auto &b) {
        return a.second.getPopulation() < b.second.getPopulation();
    });
    return it->second;
}

Settlement SettlementStatisticsImpl::minPopulation() const {
    auto it = min_element(settlements.begin(), settlements.end(),
                          [](const auto &a, const auto &b) {
                              return a.second.getPopulation() < b.second.getPopulation();
                          });
    return it->second;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> result;
    for (const auto &pair: settlements) {
        if (pair.second.getName() == name) {
            result.push_back(pair.second);
        }
    }
    return result;
}

