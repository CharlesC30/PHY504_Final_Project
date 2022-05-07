#ifndef COLORSTRING_H
#define COLORSTRING_H

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

// simple struct containing a string and colors for each char

struct color_string
{
    string characters{};
    vector<int> colors{};
};


ostream& operator<< (ostream& os, const color_string& cs) {
    /* define output operator for color strings so they print intuitively*/

    assert(cs.characters.size() == cs.colors.size());

    for (int i = 0; i < cs.characters.length(); i++) {
        os << "\033[1;" << cs.colors[i] << "m" << cs.characters[i] << "\033[0m";
    }

    return os;
}

#endif