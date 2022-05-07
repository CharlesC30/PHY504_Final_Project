#include "wordlefunc.H"

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