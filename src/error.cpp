#include "error.hpp"
#include "position.hpp"

#include <fmt/core.h>
#include <string>

using std::string;

Error::Error() {}
Error::Error(string n, string d, Position pos_s, Position pos_e) {
    name      = n;
    details   = d;
    pos_start = pos_s;
    pos_end   = pos_e;
}
string Error::as_string() const {
    return fmt::format("{0:s}: {1:s}", this->name, this->details);
}

// call parent contsructor
IllegalCharError::IllegalCharError() : Error() {}
IllegalCharError::IllegalCharError(string d, Position pos_start,
                                   Position pos_end)
    : Error("Illegal Character", d, pos_start, pos_end) {}
