#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "position.hpp"
#include <string>

using std::string;

class Error {
  public:
    string name;
    string details;
    Position pos_start, pos_end;

    Error();
    Error(string n, string d, Position pos_s, Position pos_e);

    virtual string as_string() const;
};

class IllegalCharError: public Error {
  public:
    IllegalCharError();
    IllegalCharError(string details, Position pos_start, Position pos_end);
};

#endif // ERROR_HPP_
