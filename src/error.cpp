#include "error.hpp"

#include <fmt/core.h>
#include <string>

using std::string;

Error::Error() {}
Error::Error(string n, string d) {
    name    = n;
    details = d;
}
string Error::as_string() const {
    return fmt::format("{0:s}: {1:s}", this->name, this->details);
}

// call parent contsructor
IllegalCharError::IllegalCharError() : Error() {}
IllegalCharError::IllegalCharError(string d) : Error("Illegal Character", d) {}
