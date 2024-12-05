//
// Created by Kollo Szende-Roberta on 11/28/2024.
//

#ifndef LAB10_STUDENTSERVICE_H
#define LAB10_STUDENTSERVICE_H

#include <iostream>
#include <vector>

using namespace std;
class StudentService {
    /// Ellenőrzi, hogy a megadott ID-jú diák be van-e iratkozva
    virtual bool isEnrolled(int id) const = 0;

    /// Visszaadja a megadott ID-jú diák eredményét egy adott tantárgyból
    virtual double getResultBySubject(int id, const string &subject) const = 0;

    /// Visszaadja a tantárgyak listáját, amelyeken a megadott ID-jú diák szerepel
    virtual vector<string> getSubjects(int id) const = 0;

    /// Kiszámítja és visszaadja a megadott ID-jú diák átlagát
    virtual double getAverage(int id) const = 0;

    /// Ellenőrzi, hogy a megadott ID-jú diák sikeresen teljesítette-e a tanulmányait
    virtual bool isPassed(int id) const = 0;
};



#endif //LAB10_STUDENTSERVICE_H
