//
// Created by Kollo Szende-Roberta on 11/26/2024.
//

#include "Student.h"

int Student::getId() const {
    return this->id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return this->firstName;
}

const string &Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {

    grades[subject] = grade;
}

Student::Student(int id, const string &firstName, const string &lastName) : id(id),
                                                                            firstName(firstName), lastName(lastName) {}

const map<string, double> &Student::getGrades() const {
    return grades;
}

double Student::getGrade(const string &subject) {
    if (grades.find(subject) == grades.end()) {
        throw out_of_range("Subject not found");

    }
    return grades.at(subject);
}

void Student::computeAverage() {
    if (grades.empty()) {
        average = 0.0;
        return;
    }
    double sum = 0.0;
    for (const auto &[subject, grade]: grades) {
        if (grade < 5.0) {
            average = 0.0;
            return;
        }
        sum += grade;
    }
    double atlag = sum / grades.size();
    average = (atlag > 6) ? atlag : 0.0;
}

double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << " ID " << student.id << " FIRSTNAME " << student.firstName <<
       " LASTNAME " << student.lastName << " AVERAGE " << student.average;
    return os;
}
