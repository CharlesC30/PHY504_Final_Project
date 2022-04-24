#ifndef WORDLEFUNC
#define WORDLEFUNC


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_dict() {
    /* Reads dictionary from .txt and outputs vector of strings */

    ifstream dict_file;
    dict_file.open("dict   ionary.txt");
    
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

#endif