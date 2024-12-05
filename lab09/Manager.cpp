//
// Created by Kollo Szende-Roberta on 11/18/2024.
//

#include "Manager.h"
#include <algorithm>

const string Manager::MANAGER_MUNKAKOR = "manager";

void Manager::addAlkalmazaott(Alkalmazott *alkalmazott) {
    if (find(beosztottak.begin(), beosztottak.end(), alkalmazott) == beosztottak.end()) {
        beosztottak.push_back(alkalmazott);
    } else {
        cerr << "Az alkalmzaott mar hozza van rendelve a managerhez\n";
    }
}

void Manager::deleteAlkalmazott(int alkalmazottid) {
    auto it = find_if(beosztottak.begin(), beosztottak.end(), [alkalmazottid](Alkalmazott
                                                                              *alkalmazott) {
        return alkalmazott->getId() == alkalmazottid;
    });
    if (it != beosztottak.end()) {
        beosztottak.erase(it);
    } else {
        cerr << "Az alkalmazott nem talalhato\n";
    }
}

void Manager::print(ostream &os) const {
    os << " MANAGER " << id << ": ";
    Szemely::print(os);
    os << " Beosztottak:  ";
    for (const auto &alkalmazott: beosztottak) {
        if (alkalmazott) {
            os << "\t";
            alkalmazott->print(os);
            os << "\n";
        }
    }
    Alkalmazott::print(os);
}


