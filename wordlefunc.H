#ifndef WORDLEFUNC_H
#define WORDLEFUNC_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

#include "CharCounts.H"
#include "ColorString.H"

using namespace std;

vector<string> get_dict();

string rand_word(vector<string> dict);

#endif