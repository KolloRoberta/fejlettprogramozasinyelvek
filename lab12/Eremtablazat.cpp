//
// Created by Kollo Szende-Roberta on 12/11/2024.
//

#include "Eremtablazat.h"
#include <iostream>
#include <set>
#include <map>
#include <vector>

#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Eremtablazat::Eremtablazat(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "A fajl nem elerheto " << fileName;
        return;
    }
    string line;
    while (getline(file, line)) {
        string nev, medal;
        istringstream iss(line);
        iss >> nev >> medal;
        ujMedal(nev, medal);
    }
    file.close();


}

void Eremtablazat::ujMedal(const string &nev, const string &medalTipus) {
    auto &ermek = medalok[nev];
    auto temp = find_if(ermek.begin(), ermek.end(), [&](const pair<string, int> &p) {
        return p.first == medalTipus;
    });
    if (temp != ermek.end()) {
        temp->second++;
    } else {
        ermek.emplace_back(medalTipus, 1);
    }

}

void Eremtablazat::listazas() const {
    for (const auto &[nev, medal]: medalok) {
        cout << " " << nev << " " << endl;
        for (const auto &[ermek, darabszam]: medal) {
            cout << " " << ermek << " " << darabszam << " ";
        }
        cout << endl;
    }


}

set<string> Eremtablazat::sportolok() const {
    set<string> nevek;
    for (const auto &[nev, _]: medalok) {
        nevek.insert(nev);
    }
    return nevek;
}
