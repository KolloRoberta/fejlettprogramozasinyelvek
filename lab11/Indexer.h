//
// Created by Kollo Szende-Roberta on 12/5/2024.
//

#ifndef LAB11_INDEXER_H
#define LAB11_INDEXER_H


using namespace std;

#include <iostream>
#include <map>
#include <vector>
#include <set>

class Indexer {
private:
    vector<string> kulcsszavak;
    map<string, set<int>> words;

    string toLower(const string &str);
    ////nem betu karakterek eltavolitasa
    string cleanWord(const string &word);

    ///szomszedos sorok egyesitese tartomanyokka///
    string formatLines(const vector<int> & lines);
public:
    void proccessFile(const string &fileName);

    ///targymutato kiiratas
    void generateIndex();
};

////amikor kiirjuk nagybetuve alakitja///
string toUpper(const string &str);


#endif //LAB11_INDEXER_H
