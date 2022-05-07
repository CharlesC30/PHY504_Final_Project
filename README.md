# PHY504_Final_Project
Wordle game for PHY 504 final project
by Charles Clark (SBU ID: 111590630)

Overview:

This program replicates the popular web-based game 'Wordle' (https://www.nytimes.com/games/wordle/index.html) using C++ 
During the game a secret word is hidden from the player (the answer). The player has six guesses to find the answer. 
After each guess the letters in the guess are marked grey, yellow, or green to give the player more information. 
Grey indicates the letter does not appear in the answer, yellow indicates that the letter is the answer but in a different position, and green indicates the letter is in the answer and in the correct position. 

Playing the game:

To get started first compile the code but either running 'make' or 'make wordle_game' in the terminal. Then run the wordle_game executable to start playing. Enter your guesses in the terminal until you either find the answer, or run out of guesses. To play again simply re-run the executable.

Notes on the hidden words:

The hidden answer word is randomly pulled from a text file called 'dictionary.txt'. This file currently contains all the words used as answers in the official web-based Wordle. However, it can be swapped for any single-line list of words. 
It should be noted that the program does not assume the length of the hidden words. But the program does check that the player's guesses are the same length as the answer, so it is encouraged that whatever dictionary.txt contain words all of the same length. 

Code organization:

The code for this program is organized into three header files (CharCounts.H, ColorString.H, and wordlefunc.H) as well as several program files. 
CharCounts.H defines a struct containing the unique characters of a string and their respective counts, and declares associated functions. This is useful for accurate comparison of the guess and answer words, particularly when duplicate letters appear in either.
ColorString.H defines a struct (color_string) containing a string and colors for each letter of the string. The << operator is defined for color_string such that it can be easily printed to the terminal using std::cout.
wordlefunc.H contains the remaining function declarations for the game. It also includes CharCounts.H and ColorString.H, so this is the only header that needs to be included for all game functionality.

Testing/Debugging:

To run the program in debug mode run 'make DEBUG=TRUE wordle_game' in the terminal. 
Unit testing for several important game functions is provided in unit_testing_wordle.cpp. To check all unit tests run 'make DEBUG=TRUE testing' in the terminal. This will print 'all tests passed' upon successfully completion of all tests, or return an error otherwise. 
Please note running 'make testing' will always print 'all tests passed'. Make sure to include DEBUG=TRUE when running the tests.

Enjoy!