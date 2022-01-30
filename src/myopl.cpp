#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::getline;

int main(int argc, char **argv) {
    string in;

    while (true) {
        cout << "myopl> ";
        getline(cin, in);
        cout << in << "\n";
    }
    return 0;
}
