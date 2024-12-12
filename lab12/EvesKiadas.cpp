//
// Created by Kollo Szende-Roberta on 12/11/2024.
//

#include "EvesKiadas.h"
#include <fstream>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

EvesKiadas::EvesKiadas(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << " Nem lehet megnyitni a  " << fileName;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string honap, kategoria;
        int kiadas;
        iss >> honap >> kategoria >> kiadas;
        eveskiadas[honap].emplace_back(kategoria, kiadas);

    }
    file.close();


}

void EvesKiadas::listazas() const {
    for (const auto &[honap, kategoria]: eveskiadas) {
        cout << "<" << honap << "> :  " << endl;
        for (const auto &[kategoria, osszeg]: kategoria) {
            cout << kategoria << ":" << osszeg << "" << endl;
        }
    }
    cout << endl;
}

void EvesKiadas::ujKiadas(const string &honap, const string &kiadas, int osszeg) {
    eveskiadas[honap].emplace_back(kiadas, osszeg);
}

set<string> EvesKiadas::kiadasiKategoriak() const {
    set<string> kategoriak;
    for (const auto &[_, kiadas]: eveskiadas) {
        for (const auto &[kategoria, _]: kiadas) {
            kategoriak.insert(kategoria);
        }
    }
    return kategoriak;
}

double EvesKiadas::honaponketiAtlagKiadas(const string &honap) const {
    if (honap.empty()) {
        vector<int> osszesKiadas;
        for_each(eveskiadas.begin(), eveskiadas.end(), [&](const auto &entry) {
            const auto &kiadaslista = entry.second;
            for_each(kiadaslista.begin(), kiadaslista.end(), [&](const auto &kiadas) {
                osszesKiadas.push_back(kiadas.second);
            });
        });
        return !osszesKiadas.empty() ? accumulate(osszesKiadas.begin(), osszesKiadas.end(), 0.0) / osszesKiadas.size()
                                     : 0.0;
    } else {
        auto temp = eveskiadas.find(honap);
        if (temp == eveskiadas.end()) {
            return 0.0;
        }
    }

    return 0;
}

double EvesKiadas::kategoriankentiAtlagKiadas() const {
    map<string, pair<int, int>> kategoraStat;
    for (const auto &[_, kategorialista]: eveskiadas) {
        for (const auto &[kategoria, osszeg]: kategorialista) {
            auto &[total, count] = kategoraStat[kategoria];
            total += osszeg;
            count++;
        }
    }
    /// first =  osszeg, second  = db;
    for (const auto &[kategoria, stat]: kategoraStat) {
        cout << kategoria << " " << static_cast<double> (stat.first) / stat.second << " ";
    }

    return 0;
}
