#ifndef WORDLEFUNC_H
#define WORDLEFUNC_H

#include "CharCounts.H"
#include "ColorString.H"

using namespace std;

// declare functions used in wordle game

vector<string> get_dict();

string rand_word(vector<string> dict);

color_string compare(string guess, string answer);

#endif