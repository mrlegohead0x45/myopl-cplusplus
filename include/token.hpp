#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <optional>
#include <string>

using std::string, std::optional;

// the ': char' means it has a defined conversion to char
// which will just be these values in ASCII
enum TokenType : char {
    TT_INT    = 0x49, // I
    TT_FLOAT  = 0x46, // F
    TT_PLUS   = 0x2b, // +
    TT_MINUS  = 0x2d, // -
    TT_MUL    = 0x2a, // *
    TT_DIV    = 0x2f, // /
    TT_RPAREN = 0x28, // (
    TT_LPAREN = 0x29  // )
};

// convert TokenType to string
string token_type_as_string(TokenType type);

// class for token
class Token {
  public:
    TokenType type;
    optional<string> value;
    optional<double> double_value;
    optional<int> int_value;

    Token();
    Token(TokenType t);
    Token(TokenType t, string v);
    Token(TokenType t, int i);
    Token(TokenType t, double d);

    string as_string();
};

#endif // TOKEN_HPP_
