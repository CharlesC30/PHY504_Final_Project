#include "ColorString.H"
#include "CharCounts.H"

color_string compare(string guess, string answer) {
    /* compares guess and answer then returns colored string for game output */

    assert(guess.length() == answer.length());

    // ANSI color codes
    int green = 32;
    int yellow = 33;
    int grey = 90;

    color_string output;

    output.characters = guess;
    // initialize output colors to all grey
    vector<int> init_colors (guess.length(), grey);
    output.colors = init_colors;

    char_counts ans_cc = get_counts(answer);

    // loop over unique letters of answer
    for (int i = 0; i < ans_cc.unique_char.size(); i++) {
        auto letter = ans_cc.unique_char[i];

        // important to keep track of count so that letters are not marked extra times
        auto N = ans_cc.counts[i];

        // first loop over characters in guess and check for greens
        for (int j = 0; j < guess.length(); j++) {
            if ((guess[j] == letter) && (guess[j] == answer[j])) {
                output.colors[j] = green;
                N--;
            }
        }
        
        // if there are remaining counts (N > 0) of unique character then check for yellows
        if (N > 0) {
            for (int j = 0; j < guess.length(); j++) {
                // check if letter should be marked yellow and that there are still remaining counts
                if ((guess[j] == letter) && (guess[j] != answer[j]) && (N > 0)) {
                    output.colors[j] = yellow;
                    N--;
                }
            }
        }
    }

    return output;

}