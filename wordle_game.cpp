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

    cout << "Guess the word:" << endl;

    int n_guesses = 6; // number of guesses
    int round = 1; // game round
    while (round <= n_guesses){
        
        // input guess
        string guess{};
        cin >> guess; 

        // check that guess is the correct length
        if (guess.length() != answer.length()) {
            cout << "guesses must be " << answer.length() << " letters long, enter new guess" << endl;
            continue;
        }

        else {
            color_string output = compare(guess, answer);
            // cout << round << " ";
            cout << output << endl;
        }

        if (guess == answer) {
            cout << "Congratulations! You found the word" << endl;
            break;
        }

        if (round == n_guesses) {
            cout << "Sorry, the word was " << answer << endl;
        }

        round++;

    }
    
}
