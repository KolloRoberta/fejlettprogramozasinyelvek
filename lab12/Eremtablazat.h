//
// Created by Kollo Szende-Roberta on 12/11/2024.
//

#ifndef LAB12_EREMTABLAZAT_H
#define LAB12_EREMTABLAZAT_H

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;
class Eremtablazat {
private:
    map<string, vector<pair<string, int>>> medalok;
public:
    Eremtablazat(const string & fileName);
    void listazas() const;
    void ujMedal(const string& nev, const string& medalTipus);
    set<string> sportolok() const;
    int medalokSzama(const string& medalTipus) const;
    string legtobbMedal();
};


#endif //LAB12_EREMTABLAZAT_H
