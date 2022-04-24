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

    

}
