#include <algorithm>
#include <string>
#include <vector>

using std::vector, std::string;

template <typename T> bool elem_in_vec(T elem, vector<T> vec) {
    return std::find(vec.begin(), vec.end(), elem) != vec.end();
}

bool is_digit_or_dot(int c) {
    // Between 48 (0) and 57 (9) or 46 (.)
    return ((47 < c) && (c < 58)) || (c == 46);
};

bool is_digit_or_dot(string c) {
    return is_digit_or_dot(c[0]);
}

string quote(string str){
    return "'" + str + "'";
}
