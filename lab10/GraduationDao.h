//
// Created by Kollo Szende-Roberta on 11/28/2024.
//

#ifndef CPP_2024_GRADUATIONDAO_H
#define CPP_2024_GRADUATIONDAO_H

#include <iostream>
#include <map>
#include "Student.h"

using namespace std;

class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}

    ///beolvasssa a diakok listajat es regisztralja oket a mapbe
    void enrollStudents(const string &filename);

    ///egy adott targy jegyeit  tolti be egy fajlbol, frissiti a jegyeket
    void readGradesSubject(const string &subject, const string &filename);

    ////atlagot szamol
    void computeAverage();

    ///visszaadjaa beiratkozott diakok szamat,
    ///Ez az összes olyan diákot jelenti, akiket
    /// az enrollStudents metódussal regisztráltak.
    int numEnrolled() const;

    ////visszaadja a sikeresen vegzett diakok szamat///
    int numPassed() const;

    Student findById(int id) const; //throws out_of_range exception for nonexistent id
    double getAverageBySubject(const string &subject) const;
};


#endif //CPP_2024_GRADUATIONDAO_H
