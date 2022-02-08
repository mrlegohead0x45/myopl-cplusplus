#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <optional>
#include <string>

using std::string, std::optional;

enum TokenType {
    TT_INT,
    TT_FLOAT,
    TT_PLUS,
    TT_MINUS,
    TT_MUL,
    TT_DIV,
    TT_RPAREN,
    TT_LPAREN
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

    string as_string() const;
};

#endif // TOKEN_HPP_
