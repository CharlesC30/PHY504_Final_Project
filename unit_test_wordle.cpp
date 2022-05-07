#include "wordlefunc.H"

// perform unit testing for wordle game functions

int main() {

    // test rand_word
    vector<string> test_dict {"hello", "world", "testy"};

    cout << "testing random word generation" << endl;

    auto word = rand_word(test_dict);

    // assert that the random word is in the test dictionary
    assert(find(test_dict.begin(), test_dict.end(), word) == test_dict.end()); 

    assert(1 == 0);

}