//
// Created by Kollo Szende-Roberta on 10/21/2024.
//

#ifndef LAB5_ANSWER_H
#define LAB5_ANSWER_H

#include <string>

using namespace std;
class Answer {
private:
    string text;
    bool correct;
public:
    Answer(const string& text, bool correct);
    string getText() const{
        return text;
    }
    bool isCorrect() const;
};


#endif //LAB5_ANSWER_H
