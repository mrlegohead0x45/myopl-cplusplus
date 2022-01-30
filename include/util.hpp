#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <algorithm>
#include <vector>

using std::vector;

template <typename T> bool elemInVec(vector<T> vec, T elem);

bool isDigitOrDot(int c);
bool isDigitOrDot(string c);

#endif // UTIL_HPP_
