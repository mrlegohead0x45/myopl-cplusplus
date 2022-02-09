#include "format.hpp"
#include "lexer.hpp"
#include "token.hpp"
#include <fmt/ranges.h>
#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout, std::cin, std::getline, std::vector;

int main() {
    string in;

    while (true) {
        cout << "myopl> ";
        getline(cin, in);

        if (cin.eof()) {
            exit(0);
        }

        Lexer lexer(in);
        auto [tokens, error] = lexer.make_tokens(); // structured binding

        if (error) {
            cout << error->as_string() << "\n";
        } else {
            // we can use fmt::print as we defined a formatter for Token in format.hpp
            // it also prints vectors nicely
            fmt::print("{}\n", tokens);
        }
    }
    return 0;
}
