//
// Created by Kollo Szende-Roberta on 10/21/2024.
//

#include "Question.h"

using namespace std;
#include <iostream>
Question::Question(const std::string& text, const std::vector<Answer>& answers)
        : text(text), answer(answer) {}

void Question::ask() const {
    cout<<text<<endl;
    for (int i = 0; i < answer.size(); ++i) {
        cout<< i+1 << " "<< answer[i].getText()<<endl;
    }

}

vector<int> Question::getCorrectAnswer() const {
    vector<int> correctIndexes;
    for (int i = 0; i < answer.size(); ++i) {
        if(answer[i].isCorrect()){
            correctIndexes.push_back(i);
        }
    }
    return correctIndexes;
}
