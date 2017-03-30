#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>

template<typename T>
void sort(std::vector<T> &arr) {
    std::sort(arr.begin(), arr.end());
}

#endif // SORT_H
