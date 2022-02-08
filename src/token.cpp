#include "token.hpp"
#include <fmt/core.h>
#include <string>

using std::string;

string token_type_as_string(TokenType type) {
    switch (type) {
        case TT_INT: return "INT"; break;
        case TT_FLOAT: return "FLOAT"; break;
        case TT_PLUS: return "PLUS"; break;
        case TT_MINUS: return "MINUS"; break;
        case TT_MUL: return "MUL"; break;
        case TT_DIV: return "DIV"; break;
        case TT_RPAREN: return "RPAREN"; break;
        case TT_LPAREN: return "LPAREN"; break;
        default: return "UNKNOWN"; break;
    }
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

string Token::as_string() const {
    if (this->type == TT_INT) {
        return fmt::format("INT: {0:d}", *this->int_value);
    } else if (this->type == TT_FLOAT) {
        return fmt::format("FLOAT: {0:f}", *this->double_value);
    } else {
        return token_type_as_string(this->type);
    }
}
