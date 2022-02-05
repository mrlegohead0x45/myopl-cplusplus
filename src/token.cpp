#include "token.hpp"
#include <fmt/core.h>
#include <string>

using std::string;

string token_type_as_string(TokenType type) {
    string t(1, (char)type);
    if (t == "I")
        return "INT";
    else if (t == "F")
        return "FLOAT";
    else if (t == "+")
        return "PLUS";
    else if (t == "-")
        return "MINUS";
    else if (t == "*")
        return "MUL";
    else if (t == "/")
        return "DIV";
    else if (t == "(")
        return "RPAREN";
    else if (t == ")")
        return "LPAREN";
    else
        return "UNKNOWN";
}

Token::Token(){};
Token::Token(TokenType t) { type = t; }
Token::Token(TokenType t, string v) {
    type  = t;
    value = v;
}
Token::Token(TokenType t, int i) {
    type      = t;
    int_value = i;
}
Token::Token(TokenType t, double d) {
    type         = t;
    double_value = d;
}

string Token::as_string() {
    if (this->type == TT_INT) {
        return fmt::format("INT: {0:d}", *this->int_value);
    } else if (this->type == TT_FLOAT) {
        return fmt::format("FLOAT: {0:f}", *this->double_value);
    } else {
        return token_type_as_string(this->type);
    }
}
