//
// Created by Kollo Szende-Roberta on 12/12/2024.
//

#ifndef LAB12_SIMPLETEXTGENERATOR_H
#define LAB12_SIMPLETEXTGENERATOR_H



using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include "TextGenerator.h"

class SimpleTextGenerator: public TextGenerator {
    ///elso string = prefix, masodik = postprefix
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};


#endif //LAB12_SIMPLETEXTGENERATOR_H
