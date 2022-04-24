#include <iostream>
#include <vector>
#include <string>

#include "wordlefunc.H"

using namespace std;

int main() {

    vector<string> dict = get_dict(); // read in dictionary
    
    if (dict.empty()){
        return 1; // return 1 if there was error opening dictionary.txt
    }

    string answer = rand_word(dict); // generate answer
    cout << answer << endl;

    // input guess
    string guess{};
    cout << "Guess the word:" << endl;
    cin >> guess; 

    if (guess.length() != answer.length()) {
        cout << "guesses must be " << answer.length() << " characters long, enter new guess" << endl;
    }
    
    color_string output = compare(guess, answer);
    cout << output << endl;

}
