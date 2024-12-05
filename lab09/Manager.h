//
// Created by Kollo Szende-Roberta on 11/18/2024.
//

#ifndef CPP_2024_MANAGER_H
#define CPP_2024_MANAGER_H

#include <iostream>
#include <vector>
#include "Alkalmazott.h"
#include <memory>

using namespace std;

class Manager : public Alkalmazott {
private:
    vector<Alkalmazott*> beosztottak;

public:
   static const string MANAGER_MUNKAKOR;
   Manager(string fistName, string lastName, int birthDate): Alkalmazott(firstName,lastName,birthDate, MANAGER_MUNKAKOR){}
   void addAlkalmazaott(Alkalmazott* alkalmazott);
   void deleteAlkalmazott(int alkalmazottid);
   void print(ostream & os) const override;
};


#endif //CPP_2024_MANAGER_H
