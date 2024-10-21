//
// Created by Kollo Szende-Roberta on 10/21/2024.
//

#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H

#include <iostream>
#include <vector>
#include "Question.h"

using namespace std;
class Quiz {
private:
    string name;
    vector<Question> questions;
public:

    Quiz(const string& name);
    void addQuestion(const Question& question);
    const vector<Question>& getQuestions() const;
    void loadFromFile(const string& filename);
};


#endif //LAB5_QUIZ_H
