#ifndef LEXER_HPP_
#define LEXER_HPP_

#include "token.hpp"
#include <optional>
#include <string>
#include <vector>

using std::string, std::vector, std::optional;

class Lexer {
  public:
    string text;
    int pos = -1;
    optional<string> current_char;

    Lexer();
    Lexer(string t);

    void advance();
    vector<Token> make_tokens();
    Token make_number();
};

#endif // LEXER_HPP_
