#include <iostream>
#include "Quiz.h"

using namespace std;

int main() {
    Quiz *quiz = new Quiz("Quiz");
    quiz->loadFromFile("quiz.txt");

    return 0;
}