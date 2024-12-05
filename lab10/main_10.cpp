#include <iostream>
#include "Student.h"
#include "GraduationDao.h"

using namespace std;

int main() {
    int x;
    cout << "Choose the exercise";
    cin >> x;

    switch (x) {
        case 1: {
            ////STUDENT///
            Student student = {11, "Nagy", "Laszlo"};
            student.addGrade("magyar", 8);
            student.addGrade("roman", 5);
            student.addGrade("matematika", 10);
            student.setId(3);
            student.computeAverage();
            cout << student;

            break;
        }
        case 2: {
            ///GRADUATIONDAO///
            string subjects[]{"math", "romanian", "hungarian"};
            int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
            GraduationDao dao(2023);
            dao.enrollStudents("names.txt");
            cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
            for (int i = 0; i < numSubjects; ++i) {
                dao.readGradesSubject(subjects[i], subjects[i] + string(".txt"));
            }
            dao.computeAverage();
            cout << "Number of passed students: " << dao.numPassed() << endl;
            break;
        }


    }


    return 0;
}