#include <vector>
#include <algorithm>

template <typename T>
void swap(T &a, T &b) {
    T t = a;
      a = b;
      b = t;
}

template <typename T>
void quicksort(std::vector<T> &arr, size_t l, size_t r) {
    size_t p = l;
    if (l < r) {
        T pivot = arr[r];
        for (int i = l; i < r; i++)
            if (arr[i] <= pivot) {
                swap(arr[p], arr[i]);
                p++;
            }
        swap(arr[p], arr[r]);
        if (p > 0) quicksort(arr, l, p-1);
        quicksort(arr, p+1, r);
    }
}

template<typename T>
void sort(std::vector<T> &arr) {
    quicksort(arr, 0, arr.size()-1);
}
