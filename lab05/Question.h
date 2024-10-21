//
// Created by Kollo Szende-Roberta on 10/21/2024.
//

#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H

#include <vector>
#include "Answer.h"

using namespace std;

class Question {
private:
    string text;
    vector<Answer> answer;
public:
    Question(const string& text, const vector<Answer>& answer);
    void ask()const;
    vector<int> getCorrectAnswer()const;
};


#endif //LAB5_QUESTION_H
