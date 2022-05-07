#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <time.h>

using namespace std;

// functions for generating wordle answers (get the dictionary and pick a random word)

vector<string> get_dict() {
    /* Reads dictionary from .txt and outputs as a vector of strings */

    ifstream dict_file;
    dict_file.open("dictionary.txt");
    
    vector<string> dict{}; // vector of dictionary words

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