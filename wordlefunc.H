#ifndef WORDLEFUNC
#define WORDLEFUNC


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

using namespace std;

vector<string> get_dict() {
    /* Reads dictionary from .txt and outputs vector of strings */

    ifstream dict_file;
    dict_file.open("dictionary.txt");
    
    vector<string> dict{}; // dict will be vector of dictionary words

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

struct output
{
    string characters{};
    vector<int> colors{};
};

ostream& operator<< (ostream& os, const output& op) {
    /* allow cout to be used for printing colored text output */
    for (int i = 0; i < op.characters.length(); i++) {
        os << "\033[1;" << op.colors[i] << "m" << op.characters[i] << "\033[0m";
    }

    return os;
}

#endif