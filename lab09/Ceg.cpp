//
// Created by Kollo Szende-Roberta on 11/18/2024.
//

#include "Ceg.h"

void Ceg::alkalmaz(Szemely *szemely) {
    alkalmazottak.push_back(szemely);
}

void Ceg::elbocsat(int id) {
    alkalmazottak.erase(
            std::remove_if(alkalmazottak.begin(), alkalmazottak.end(),
                           [id](Szemely *szemely) {
                               auto alkalmazott = dynamic_cast<Alkalmazott *>(szemely);
                               return alkalmazott && alkalmazott->getId() == id;
                           }),
            alkalmazottak.end());
}

void Ceg::hozzarendelManagerhez(int alkalmazottId, Manager *manager) {
    for (auto szemely: alkalmazottak) {
        auto alkalmazott = dynamic_cast<Alkalmazott *>(szemely);
        if (alkalmazott && alkalmazott->getId() == alkalmazottId) {
            manager->addAlkalmazaott(alkalmazott);
            return;
        }
    }
}

void Ceg::levalasztManagerrol(int alkalmazottId, Manager *manager) {
    manager->deleteAlkalmazott(alkalmazottId);
}

void Ceg::listazOsszesAlkalmazott() const {
    for (const auto &szemely: alkalmazottak) {
        cout << *szemely << endl;
    }
}

void Ceg::listazManager() {
    for (const auto &szemely: alkalmazottak) {
        if (dynamic_cast<const Manager *>(szemely)) {
            cout << szemely << endl;
        }
    }
}
