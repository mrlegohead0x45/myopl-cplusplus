#include "lexer.hpp"
#include "token.hpp"
#include "util.hpp"
#include <optional>
#include <string>
#include <vector>

using std::string, std::nullopt, std::vector;

Lexer::Lexer() {}
Lexer::Lexer(string t) {
    text = t;
    this->advance();
}

void Lexer::advance() {
    this->pos++;
    if (this->pos < this->text.length()) {
        this->current_char = string(1, this->text[this->pos]);
        return;
    } else {
        this->current_char = nullopt;
    }
}

vector<Token> Lexer::make_tokens() {
    vector<Token> tokens;

    while (this->current_char != nullopt) {
        if (*this->current_char == " " || *this->current_char == "\t") {
            this->advance();
        } else if (is_digit_or_dot(*this->current_char)) {
            tokens.push_back(this->make_number());
        } else if (*this->current_char == "+") {
            tokens.push_back(Token(TT_PLUS));
            this->advance();
        } else if (*this->current_char == "-") {
            tokens.push_back(Token(TT_MINUS));
            this->advance();
        } else if (*this->current_char == "*") {
            tokens.push_back(Token(TT_MUL));
            this->advance();
        } else if (*this->current_char == "/") {
            tokens.push_back(Token(TT_DIV));
            this->advance();
        } else if (*this->current_char == "(") {
            tokens.push_back(Token(TT_RPAREN));
            this->advance();
        } else if (*this->current_char == ")") {
            tokens.push_back(Token(TT_LPAREN));
            this->advance();
        }
    }
}
