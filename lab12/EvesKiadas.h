//
// Created by Kollo Szende-Roberta on 12/11/2024.
//

#ifndef LAB12_EVESKIADAS_H
#define LAB12_EVESKIADAS_H

#include <map>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class EvesKiadas {
private:
    map<string, vector<pair<string, int>>> eveskiadas;
public:
    EvesKiadas(const string &fileName);
    void listazas() const;
    void ujKiadas(const string& honap, const string & kiadas, int osszeg);
    set<string> kiadasiKategoriak() const;
    double honaponketiAtlagKiadas(const string& honap) const;
    double kategoriankentiAtlagKiadas() const;
};

#endif //LAB12_EVESKIADAS_H
