#include "wordlefunc.H"

// perform unit testing for wordle game functions

int main() {

    // test rand_word

    vector<string> test_dict {"hello", "world", "testy"};

    cout << "testing random word generation" << endl;

    auto word = rand_word(test_dict);

    // assert that the random word is in the test dictionary
    assert(find(test_dict.begin(), test_dict.end(), word) != test_dict.end()); 

    // test get_counts

    cout << "testing get counts" << endl;

    string test_str{"hello_world"};
    auto test_charcounts = get_counts(test_str);
    
    vector<char> real_char{'h','e','l','o','_','w','r','d'};
    vector<int> real_counts{1,1,3,2,1,1,1,1};
    
    assert((test_charcounts.unique_char == real_char) && (test_charcounts.counts == real_counts));    

    // test comparison of guess and answer

    cout << "testing guess-answer comparison" << endl;

    string test_guess{"hello"};
    string test_answer{"world"};

    auto test_comp = compare(test_guess, test_answer);

    vector<int> real_colors{90,90,90,32,33};

    assert(test_comp.colors == real_colors);

}