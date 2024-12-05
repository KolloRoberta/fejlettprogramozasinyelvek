#include "Alkalmazott.h"

int Alkalmazott::pluszid = 1;

Alkalmazott::Alkalmazott(const string &firstName, const string &lastName, int birthDate, const string &work) : Szemely(
        firstName, lastName, birthDate), work(work) {
        id = pluszid++;
}

int Alkalmazott::getId() const {
    return id;
}

const string &Alkalmazott::getWork() const {
    return work;
}

void Alkalmazott::print(ostream &os) const {
    Szemely::print(os);
    os<< " Id " << id << " Work " << work;
}
