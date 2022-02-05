#include "lexer.hpp"
#include "token.hpp"
#include <fmt/ranges.h>
#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout, std::cin, std::getline, std::vector;

int main(int argc, char **argv) {
    string in;

    while (true) {
        cout << "myopl> ";
        getline(cin, in);

        Lexer lexer(in);
        auto [tokens, error] = lexer.make_tokens(); // structured binding

        if (error) {
            cout << (*error).as_string() << "\n";
        } else {
            vector<string> tokens_as_strings;
            for (Token t : tokens) {
                tokens_as_strings.push_back(t.as_string());
            }
            fmt::print("{}\n", tokens_as_strings);
        }
    }
    return 0;
}
