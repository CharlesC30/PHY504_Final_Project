#include "wordlefunc.H"

string rand_word(vector<string> dict) {
    /* picks random word from dictionary */
    srand (time(NULL)); // pseudo-random number seed
    int rand_ind = rand() % dict.size(); // generate random number in range of dictionary size
    string word = dict[rand_ind];
    return word;

}
