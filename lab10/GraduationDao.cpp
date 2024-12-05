//
// Created by Kollo Szende-Roberta on 11/28/2024.
//

#include "GraduationDao.h"
#include <fstream>
#include <sstream>

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw out_of_range("Error with the file " + filename);
    }
    string line;
    while (getline(file, line)) {
        stringstream is(line);
        int id;
        double grades;
        is >> id >> grades;
        auto it = students.find(id);
        if (it != students.end()) {
            it->second.addGrade(subject, grades);

        } else {
            cerr << "Error with id " << id << endl;
        }
    }
    file.close();

}

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw out_of_range(" Error with the file" + filename);
    }
    string line;
    while (getline(file, line)) {
        stringstream is(line);
        int id;
        string firstname, lastname;
        is >> id >> firstname >> lastname;
        //students.emplace(id, Student(id, firstname, lastname));
        students.insert(pair(id, Student(id, firstname, lastname)));
    }
    file.close();
}

void GraduationDao::computeAverage() {
    for (auto &[id, student]: students) {
        student.computeAverage();
    }

}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for (const auto &[id, student]: students) {
        const auto &grades = student.getGrades();
        if (grades.size() >= 3) {
            bool passedAll = true;
            for (const auto &[subject, grade]: grades) {
                if (grade < 5.0) {
                    passedAll = false;
                    break;
                }
            }
            if (passedAll && student.getAverage() >= 6.0) {
                ++count;
            }
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    if (students.find(id) == students.end()) {
        throw out_of_range("Student is not found");
    }
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double total = 0.0;
    int count = 0;

    for (const auto &[id, student]: students) {
        auto it = student.getGrades().find(subject);
        if (it != student.getGrades().end()) {
            total += it->second;
            ++count;
        }
    }

    if (count == 0) {
        return 0.0;
    } else {
        return total / count;
    }
}
