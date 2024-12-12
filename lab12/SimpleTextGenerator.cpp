//
// Created by Kollo Szende-Roberta on 12/12/2024.
//

#include "SimpleTextGenerator.h"

using namespace std;

#include <iostream>
#include <vector>
#include <map>
#include <sstream> ///stringekre jooo

#include <utility>
#include <algorithm>
#include <fstream>

void SimpleTextGenerator::trainFromText(string trainingText) {
    istringstream iss(trainingText);

    string word1, word2, word3;
    if (!(iss >> word1 >> word2)) {
        // Not enough words to train
        return;
    }

    while (iss >> word3) {
        string key = word1 + " " + word2;

        // Add word3 to the vector corresponding to the key
        if (data.find(key) == data.end()) {
            data[key] = vector<string>(); // Initialize vector if key doesn't exist
        }
        data[key].push_back(word3);

        // Slide the window
        word1 = word2;
        word2 = word3;
    }
}
string SimpleTextGenerator::generate(string startWords, int numWords) {
    string sentence;
    string chosen;
    string word1, word2;

    // Parse the startWords into two words
    istringstream iss(startWords);
    if (!(iss >> word1 >> word2)) {
        cerr << "Error: startWords must contain at least two words." << endl;
        return "";
    }

    sentence += word1 + " " + word2 + " ";

    for (int i = 0; i < numWords; i++) {
        string key = word1 + " " + word2;

        auto it = data.find(key);
        if (it == data.end() || it->second.empty()) {
            return sentence; // Stop if no continuation is found
        }
        // Randomly select the next word from the vector of options
        const vector<string>& options = it->second;
        srand(static_cast<unsigned>(time(nullptr)) + i); // Seed the random generator
        chosen = options[rand() % options.size()];

        sentence += chosen + " ";

        // Shift words for the next iteration
        word1 = word2;
        word2 = chosen;
    }

    return sentence;
}

void SimpleTextGenerator::printData() const {
    for (const auto& [key, value] : data) {
        cout << key << ": { ";
        for (const auto& val : value) {
            cout << val << " ";
        }
        cout << "}" << endl;
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << " Nem lehet megnyitni a " << filename;
        return;
    }
    string line;
    string word1, word2, word3;
    while (getline(file, line)) {
        istringstream iss(line);
        while (iss >> word3) {
            string key = word1 + " " + word2;

            // Add word3 to the vector corresponding to the key
            if (data.find(key) == data.end()) {
                data[key] = vector<string>(); // Initialize vector if key doesn't exist
            }
            data[key].push_back(word3);

            // Slide the window
            word1 = word2;
            word2 = word3;
        }
    }


}
