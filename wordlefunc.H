#ifndef WORDLEFUNC_H
#define WORDLEFUNC_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

#include "CharCounts.H"

using namespace std;

vector<string> get_dict() {
    /* Reads dictionary from .txt and outputs vector of strings */

    ifstream dict_file;
    dict_file.open("dictionary.txt");
    
    vector<string> dict{}; // vector of dictionary words

    string line{};

    if (! dict_file.is_open()){
        cout << "Error opening dictionary.txt" << endl;
    }

    string word{};
    while(getline(dict_file, word)) {
        dict.push_back(word);
    }

    return dict;

}

string rand_word(vector<string> dict) {
    /* picks random word from dictionary */
    srand (time(NULL)); // pseudo-random number seed
    int rand_ind = rand() % dict.size(); // generate random number in range of dictionary size
    string word = dict[rand_ind];
    return word;

}


struct color_string
{
    string characters{};
    vector<int> colors{};
};

color_string compare(string guess, string answer) {
    /* compares guess and answer then returns colored string */

    // ANSI color codes
    int green = 32;
    int yellow = 33;
    int grey = 90;

    color_string output;

    output.characters = guess;

    // loop over index of characters in guess
    for (int i = 0; i < guess.length(); i++) {
                
        bool inWord = false;
        bool rightPlace = false;

        // loop over index of characters in answer
        for (int j = 0; j < answer.length(); j++) {
        
            // check if guess character matches answer character
            if (guess[i] == answer[j]) {
                inWord = true;
                // check if index/location is the same
                if (i == j) {
                    rightPlace = true;
                }
            }
        }

        if (inWord && rightPlace) {
            output.colors.push_back(green);
        }
        else if (inWord) {
            output.colors.push_back(yellow);
        }
        else {
            output.colors.push_back(grey);
        }

    }

    return output;

}


ostream& operator<< (ostream& os, const color_string& cs) {
    /* define ostream for colored strings */
    for (int i = 0; i < cs.characters.length(); i++) {
        os << "\033[1;" << cs.colors[i] << "m" << cs.characters[i] << "\033[0m";
    }

    return os;
}

#endif