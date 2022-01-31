#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <algorithm>
#include <vector>

using std::vector;

template <typename T> bool elem_in_vec(vector<T> vec, T elem);

bool is_digit_or_dot(int c);
bool is_digit_or_dot(string c);

#endif // UTIL_HPP_
