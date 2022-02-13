#ifndef POSITION_HPP_
#define POSITION_HPP_

#include <string>

using std::string;

struct PositionArgs {
    int idx = 0;
    int ln  = 0;
    int col = 0;
};

class Position {
  public:
    int idx;
    int ln;
    int col;

    Position();
    Position(PositionArgs args);

    void advance(string current_char);
    Position copy();
};

#endif // POSITION_HPP_
