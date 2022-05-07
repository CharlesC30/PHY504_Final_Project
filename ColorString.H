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

ostream& operator<< (ostream& os, const color_string& cs);

color_string compare(string guess, string answer);

#endif