/*
Read dictionary.txt and return a vector of words in dictionary
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    ifstream dict_file;
    dict_file.open("dictionary.txt");
    
    vector<string> dict; // dict will be vector of dictionary words

    string line{};

    if (! dict_file.is_open()){
        cout << "Error opening dictionary.txt" << endl;
        return 1;
    }

    string word{};
    while(getline(dict_file, word)) {
        dict.push_back(word);
    }

    for (auto e : dict) {
        cout << e << endl;
    }

}
