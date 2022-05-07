#include "ColorString.H"

ostream& operator<< (ostream& os, const color_string& cs) {
    /* define output operator for color strings so they print intuitively*/

    assert(cs.characters.size() == cs.colors.size());

    for (unsigned int i = 0; i < cs.characters.length(); i++) {
        os << "\033[1;" << cs.colors[i] << "m" << cs.characters[i] << "\033[0m";
    }

    return os;
}
