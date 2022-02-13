#ifndef LEXER_HPP_
#define LEXER_HPP_

#include "error.hpp"
#include "token.hpp"
#include <optional>
#include <string>
#include <vector>
#include "position.hpp"

using std::string, std::optional, std::vector;

struct LexResult {
    vector<Token> tokens;
    optional<Error> error;
};

class Lexer {
  public:
    string text;
    Position pos = Position({.idx = -1, .ln = 0, .col = -1});
    optional<string> current_char;

    Lexer();
    Lexer(string t);

    void advance();
    LexResult make_tokens();
    Token make_number();
};

#endif // LEXER_HPP_
