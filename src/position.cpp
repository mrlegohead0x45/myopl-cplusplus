#include "position.hpp"

#include <string>

using std::string;

Position::Position() {}
Position::Position(PositionArgs args) {
    idx = args.idx;
    ln  = args.ln;
    col = args.col;
}

void Position::advance(string current_char) {
    this->idx++;
    this->col++;

    if (current_char == "\n") {
        this->ln++;
        this->col = 0;
    }
}

Position Position::copy() {
    return Position({.idx = this->idx, .ln = this->ln, .col = this->col});
}
