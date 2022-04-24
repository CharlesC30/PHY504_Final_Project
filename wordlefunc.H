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
    // initialize output colors to all grey
    vector<int> init_colors (guess.length(), grey);
    output.colors = init_colors;

    char_counts ans_cc = get_counts(answer);

    // loop over unique letters of answer
    for (int i = 0; i < ans_cc.unique_char.size(); i++) {
        auto letter = ans_cc.unique_char[i];

        // important to keep track of count so that letters are not marked extra times
        auto N = ans_cc.counts[i];

        // first loop over characters in guess and check for greens
        for (int j = 0; j < guess.length(); j++) {
            if ((guess[j] == letter) && (guess[j] == answer[j])) {
                output.colors[j] = green;
                N--;
            }
        }
        
        // if there are remaining counts (N > 0) of unique character then check for yellows
        if (N > 0) {
            for (int j = 0; j < guess.length(); j++) {
                // check if letter should be marked yellow and that there are still remaining counts
                if ((guess[j] == letter) && (guess[j] != answer[j]) && (N > 0)) {
                    output.colors[j] = yellow;
                    N--;
                }
            }
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