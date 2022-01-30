#include "lexer.hpp"
#include <vector>
#include <string>

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
        this->current_char = "";
    }
}

vector<string> Lexer::make_tokens(){
    
}
