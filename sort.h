#include <vector>
#include <algorithm>

template<typename T>
void sort(std::vector<T> &arr) {
    std::stable_sort(arr.begin(), arr.end());
}
