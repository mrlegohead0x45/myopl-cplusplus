#include "token.hpp"
#include <fmt/core.h>
#include <string>

using std::string;

string tokenTypeAsString(TokenType type) {
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
    type     = t;
    intValue = i;
}
Token::Token(TokenType t, double d) {
    type        = t;
    doubleValue = d;
}

string Token::asString() {
    if (this->type == TT_INT) {
        return fmt::format("INT: {0:d}", this->intValue);
    } else if (this->type == TT_FLOAT) {
        return fmt::format("FLOAT: {0:f}", this->doubleValue);
    } else {
        return tokenTypeAsString(this->type);
    }
}
