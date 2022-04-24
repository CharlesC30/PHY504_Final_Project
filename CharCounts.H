#ifndef CHARCOUNTS_H
#define CHARCOUNTS_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct char_counts
{
    // containes unique characters of a string and their counts
    vector<char> unique_char{};
    vector<int> counts{};
};

char_counts get_counts(string str) {
    
    vector<char> unique{};
    for (auto c : str) {

        // check if letter is not in unique vector
        if (find(unique.begin(), unique.end(), c) == unique.end()) {
            unique.push_back(c);
        }
    }

    // initialize counts of each unique letter to zero
    vector<int> cnt (unique.size(), 0);

    // loop over unique characters
    for (int i = 0; i < unique.size(); i++) {
        auto u = unique[i];
        for (auto c : str) {
            if (u == c) {
                // increment count of character if it's found in string
                cnt[i]++;
            }
        }
    }

    char_counts cc{};
    cc.unique_char = unique;
    cc.counts = cnt;
    return cc;

}

#endif