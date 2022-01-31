#include <algorithm>
#include <string>
#include <vector>

using std::vector, std::string;

template <typename T> bool elemInVec(vector<T> vec, T elem) {
    return std::find(vec.begin(), vec.end(), elem) != vec.end();
}

bool is_digit_or_dot(int c) {
    // Between 48 (0) and 57 (9) or 46 (.)
    return ((47 < c) && (c < 58)) || (c == 46);
};

bool isDigitOrDot(string c) {
    return is_digit_or_dot(c[0]);
}
