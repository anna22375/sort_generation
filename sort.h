#ifndef INTROSORT
#define INTROSORT
#include <vector>
template<typename T>
void introsort(std::vector<T> &arr);

template<typename T>
void introsort1(std::vector<T> &arr, int x1, int x2, int maxdepth);

template<typename T>
void siftDown(std::vector<T> &arr, int i, int n);

template<typename T>
void makeHeap(std::vector<T> &arr, int x1, int x2);

template<typename T>
void heapsort(std::vector<T> &arr, int x1, int x2);
#endif
