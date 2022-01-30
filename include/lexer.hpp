#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <string>
#include <vector>
#include "token.hpp"

using std::string, std::vector;

class Lexer {
  public:
    string text;
    int pos = -1;
    string current_char;

    Lexer();
    Lexer(string t);

    void advance();
    vector<string> make_tokens();
};

#endif // LEXER_HPP_
