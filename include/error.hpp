#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>

using std::string;

class Error {
  public:
    string name;
    string details;

    Error();
    Error(string n, string d);

    virtual string as_string();
};

class IllegalCharError: public Error {
  public:
    IllegalCharError();
    IllegalCharError(string details);

    // string as_string();
};

#endif // ERROR_HPP_
