#include "format.hpp"
#include "lexer.hpp"
#include "token.hpp"
#include <fmt/ranges.h>
#include <iostream>
#include <string>
#include <vector>

#include "loguru.hpp"

using std::string, std::cout, std::cin, std::getline, std::vector;

int main() {
    loguru::add_file("myopl.log", loguru::Append, loguru::Verbosity_MAX);
    string in;

    while (true) {
        cout << "myopl> ";
        getline(cin, in);
        LOG_F(INFO, "Read input");

        if (cin.eof()) {
            return 0;
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
