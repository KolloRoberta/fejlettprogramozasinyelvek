//
// Created by Kollo Szende-Roberta on 11/26/2024.
//

#ifndef CPP_2024_STUDENT_H
#define CPP_2024_STUDENT_H

using namespace std;

#include <iostream>
#include <map>

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades; ///string = tantargy , double = jegy //grades =
    double average{0.0};
public:
    Student(int id, const string &firstName, const string &lastName);

    int getId() const;

    void setId(int id);

    const string &getFirstName() const;

    const string &getLastName() const;
    ///jegyek kezelese
    void addGrade(const string &subject, double grade);
    ////egy konkret tantargy jegyeinek lekerdezese
    double getGrade(const string &subject);

    const map<string, double> &getGrades() const;
    ////atlag kiszamitasa
    void computeAverage() ;

    double getAverage() const;

    friend ostream &operator<<(ostream &os, const Student &student);
};


#endif //CPP_2024_STUDENT_H
