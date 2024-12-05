//
// Created by Kollo Szende-Roberta on 11/18/2024.
//

#ifndef CPP_2024_CEG_H
#define CPP_2024_CEG_H

#include <iostream>
#include <vector>
#include "Szemely.h"
#include "Manager.h"
#include "Alkalmazott.h"
#include <algorithm>

using namespace std;

class Ceg {
private:
    vector<Szemely *> alkalmazottak;
public:
    void alkalmaz(Szemely* szemely);
    void elbocsat(int id);
    void hozzarendelManagerhez(int alkalmazottId, Manager* manager);
    void levalasztManagerrol(int alkalmazottId, Manager* manager);
    void listazOsszesAlkalmazott() const;
    void listazManager();
};


#endif //CPP_2024_CEG_H
