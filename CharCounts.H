#ifndef CHARCOUNTS_H
#define CHARCOUNTS_H

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct char_counts
{
    // contains unique characters of a string and their counts
    vector<char> unique_char{};
    vector<int> counts{};
};

char_counts get_counts(string str);

#endif