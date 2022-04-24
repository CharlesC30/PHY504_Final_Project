#include <iostream>
#include <vector>
#include <string>

#include "wordlefunc.H"

using namespace std;

int main() {

    vector<string> dict = get_dict();
    
    if (dict.empty()){
        return 1; // return 1 if there was error opening dictionary.txt
    }

    string answer = rand_word(dict);
    cout << answer << endl;

    string guess{};
    cout << "Guess the word:" << endl;
    cin >> guess;

    if (guess.length() != answer.length()) {
        cout << "guesses must be " << answer.length() << " characters long, enter new guess" << endl;
    }

    // cout << "\033[34mbold red text\033[0m\n";    
    // output x;
    // x.characters = "hello wordle";
    // cout << x << endl;

}
