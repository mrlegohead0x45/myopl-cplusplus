#ifndef POSITION_HPP_
#define POSITION_HPP_

#include <string>

using std::string;
using size_t = string::size_type;

struct PositionArgs {
    size_t idx = 0;
    size_t ln  = 0;
    size_t col = 0;
};

class Position {
  public:
    size_t idx;
    size_t ln;
    size_t col;

    Position();
    Position(PositionArgs args);

    void advance(string current_char);
    Position copy();
};

#endif // POSITION_HPP_
