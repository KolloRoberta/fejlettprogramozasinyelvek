//
// Created by Kollo Szende-Roberta on 10/21/2024.
//

#include <fstream>
#include <sstream>
#include "Quiz.h"
#include "Answer.h"

Quiz::Quiz(const std::string &name) : name(name) {}

void Quiz::addQuestion(const Question &question) {
    questions.push_back(question);
}

const std::vector<Question> &Quiz::getQuestions() const {
    return questions;
}

void Quiz::loadFromFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ilyen nincs";
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line[0] == 'Q') {
            string questionText = line.substr(2);
            vector<Answer> answer;
            while (getline(file, line) && line[0] == 'A') {
                string answerText = line.substr(2);
                answer.emplace_back(Answer(answerText, false));
            }
            int correctAnswer;
            istringstream iss(line);//egyiranyu
            while (iss >> correctAnswer) {
                if (correctAnswer > 0 && correctAnswer <= answer.size()) {
                    answer[correctAnswer-1] = Answer(answer[correctAnswer-1].getText(), true);
                }
            }

            addQuestion(Question(questionText, answer));

        }
    }

}
