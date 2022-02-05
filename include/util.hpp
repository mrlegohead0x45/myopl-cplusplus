#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <algorithm>
#include <vector>

using std::vector, std::string;

template <typename T> bool elem_in_vec(T elem, vector<T> vec);

bool is_digit_or_dot(int c);
bool is_digit_or_dot(string c);

string quote(string str);

#endif // UTIL_HPP_
