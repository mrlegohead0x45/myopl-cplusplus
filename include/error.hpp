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

    virtual string as_string() const;
};

class IllegalCharError: public Error {
  public:
    IllegalCharError();
    IllegalCharError(string details);
};

#endif // ERROR_HPP_
