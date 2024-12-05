#ifndef CPP_2024_ALKALMAZOTT_H
#define CPP_2024_ALKALMAZOTT_H

#include <iostream>
#include "Szemely.h"

using namespace std;

class Alkalmazott : public Szemely {
protected:
    int id;
    string work;
    static int pluszid;
public:
    Alkalmazott(const string &firstName, const string &lastName, int birthDate, const string &work);

    int getId() const;

    const string &getWork() const;
    void print(ostream & os) const override;
};


#endif // CPP_2024_ALKALMAZOTT_H
