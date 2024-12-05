//
// Created by Kollo Szende-Roberta on 12/5/2024.
//

#include "Indexer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>

string Indexer::toLower(const string &str) {
    string result;
    transform(str.begin(), str.end(), back_inserter(result), ::tolower);
    return result;
}

string Indexer::cleanWord(const string &word) {
    regex pattern("[^a-zA-Z]"); // Nem betű karakterek eltávolítása
    return regex_replace(word, pattern, "");
}

string Indexer::formatLines(const vector<int> &lines) {
    string result;
    int n = lines.size();
    for (int i = 0; i < n; ++i) {
        int start = lines[i];
        while (i + 1 < n && lines[i + 1] == lines[i] + 1) {
            ++i;
        }
        int end = lines[i];
        if (!result.empty()) {
            result += ", ";
        }
        if (start == end) {
            result += to_string(start);
        } else {
            result += to_string(start) + "-" + to_string(end);
        }
    }
    return result;
}

void Indexer::proccessFile(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Nem sikerült megnyitni a " + fileName << endl;
        return; // Kilép a függvényből
    }

    string line;
    bool kulcsszo = true;
    int lineNumber = 0;
    while (getline(file, line)) {
        if (line.empty()) {
            kulcsszo = false;
            continue;
        }
        if (kulcsszo) {
            kulcsszavak.push_back(toLower(line));
        } else {
            lineNumber++;
            stringstream is(line);
            string word;
            while (is >> word) {
                word = toLower(cleanWord(word));
                if (!word.empty()) {
                    words[word].insert(lineNumber);
                }
            }
        }
    }
    file.close();
}

void Indexer::generateIndex() {
    for (const auto &keyword : kulcsszavak) {
        cout << toUpper(keyword) << " ";
        if (words.find(keyword) != words.end()) {
            vector<int> lines(words[keyword].begin(), words[keyword].end());
            cout << formatLines(lines);
        }
        cout << endl;
    }
}

string toUpper(const string &str) {
    string result;
    transform(str.begin(), str.end(), back_inserter(result), ::toupper);
    return result;
}
