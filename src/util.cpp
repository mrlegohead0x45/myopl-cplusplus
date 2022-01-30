#include <vector>
#include <algorithm>

using std::vector;

template<typename T>
bool elemInVec(vector<T> vec, T elem){
    return std::find(vec.begin(), vec.end(), elem) != vec.end();
}
