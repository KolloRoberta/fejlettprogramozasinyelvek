//
// Created by Kollo Szende-Roberta on 10/21/2024.
//

#include "Answer.h"

Answer::Answer(const string &text, bool correct):
    text(text), correct(correct){}

bool Answer::isCorrect() const {
    return correct;
}

