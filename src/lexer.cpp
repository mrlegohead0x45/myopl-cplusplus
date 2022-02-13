#include "lexer.hpp"
#include "token.hpp"
#include "util.hpp"
#include <optional>
#include <string>

using std::string, std::nullopt;

Lexer::Lexer() {}
Lexer::Lexer(string t) {
    text = t;
    this->advance();
}

void Lexer::advance() {
    this->pos.advance();
    if (this->pos.idx < this->text.length()) {
        this->current_char = string(1, this->text[this->pos]);
        return;
    } else {
        this->current_char = nullopt;
    }
}

Token Lexer::make_number() {
    string num_str;
    int dot_count = 0;

    while (this->current_char != nullopt &&
           is_digit_or_dot(*this->current_char)) {
        if (*this->current_char == ".") {
            if (dot_count == 1) {
                break;
            }
            dot_count++;
            num_str += ".";

        } else {
            num_str += *this->current_char;
        }
        this->advance();
    };

    if (dot_count == 0) {
        return Token(TT_INT, std::stoi(num_str));
    } else {
        return Token(TT_FLOAT, std::stod(num_str));
    }
}

LexResult Lexer::make_tokens() {
    LexResult result;

    while (this->current_char != nullopt) {
        if (*this->current_char == " " || *this->current_char == "\t") {
            this->advance();
        } else if (is_digit_or_dot(*this->current_char)) {
            result.tokens.push_back(this->make_number());
        } else if (*this->current_char == "+") {
            result.tokens.push_back(Token(TT_PLUS));
            this->advance();
        } else if (*this->current_char == "-") {
            result.tokens.push_back(Token(TT_MINUS));
            this->advance();
        } else if (*this->current_char == "*") {
            result.tokens.push_back(Token(TT_MUL));
            this->advance();
        } else if (*this->current_char == "/") {
            result.tokens.push_back(Token(TT_DIV));
            this->advance();
        } else if (*this->current_char == "(") {
            result.tokens.push_back(Token(TT_LPAREN));
            this->advance();
        } else if (*this->current_char == ")") {
            result.tokens.push_back(Token(TT_RPAREN));
            this->advance();
        } else {
            string character(*this->current_char);
            this->advance();

            return {.tokens = {}, .error = IllegalCharError(quote(character))};
        }
    }

    return result;
}
